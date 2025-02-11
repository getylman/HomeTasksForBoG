#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    size_t whole;
    size_t numerator;
    size_t denominator;
} Fraction; 

typedef struct {
    unsigned x, y, z, y_size, z_size;
} SeparatedData; // naming from tech task

Fraction ConvertStr2Fraction(const char* str);

Fraction SumOfFractions(const Fraction* a, const Fraction* b);

char* ConvertFraction2Str(const Fraction* drob);

void Solution(const char* a, const char* b) {
    const Fraction fa = ConvertStr2Fraction(a);
    const Fraction fb = ConvertStr2Fraction(b);

    const Fraction fsum = SumOfFractions(&fa, &fb);

    char* res = ConvertFraction2Str(&fsum);

    if (res) {
        printf("%s", res);
    }

    free(res);
}

int main() {
    char a[30] = "";
    char b[30] = "";

    scanf("%s%s", a, b);

    Solution(a, b);
    
    return 0;
}

size_t StupidPow(size_t a, size_t n) {
    size_t res = a;
    for (int i = 1; i < n; ++i) {
        res *= a;
    }
    if (n == 0) {
        return 1;
    }
    return res;
}

size_t DigitDupper(size_t dig, size_t n) {
    size_t res = dig;
    for (size_t i = 1; i < n; ++i) {
        res *= 10;
        res += dig;
    }
    if (n == 0) {
        return 1;
    }
    return res;
}

SeparatedData Sepatator(const char* str) {
    SeparatedData res = {0, 0, 0, 0, 0};

    unsigned buf = 0;
    const char kDotSeparator = '.';
    const char kPeriodSeparator = '(';
    const char kEndOfNumberSeparator = ')';

    int has_period = 0;
    int has_drop_part = 0;

    int drop_cntr = 0;
    int period_cntr = 0;
    int cntr = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == kDotSeparator) {
            res.x = buf;
            buf = 0;
            has_drop_part = 1;
            cntr = 0;
        } else if (str[i] == kPeriodSeparator) {
            res.y = buf;
            buf = 0;
            has_period = 1;
            drop_cntr = cntr;
            cntr = 0;
        } else if (str[i] == kEndOfNumberSeparator) {
            res.z = buf;
            buf = 0;
            period_cntr = cntr;
            cntr = 0;
        } else {
            buf *= 10;
            buf += str[i] - '0';
            ++cntr;
        }
    }
    if (!has_drop_part) {
        res.x = buf;
    } else if (!has_period) {
        res.y = buf;
        drop_cntr = cntr;
    }
    if (res.y == 0) {
        drop_cntr = 0;
    }
    if (res.z == 0) {
        period_cntr = 0;
    }

    res.y_size = drop_cntr;
    res.z_size = period_cntr;

    return res;
}

size_t MinSizeT(size_t a, size_t b) {
    return (a < b) ? a : b;
}

Fraction ConvertStr2Fraction(const char* str) {
    const SeparatedData data = Sepatator(str);

    const size_t kNumerator = data.z_size ? ((data.y * StupidPow(10, data.z_size) + data.z) - data.y) : data.y;
    const size_t kDenominator = (!data.y && !data.z) ? 1 : DigitDupper(9, data.z_size) * StupidPow(10, data.y_size);

    const size_t kNumeratorRes = kNumerator % kDenominator;
    const size_t kDenominatorRes = kNumeratorRes ? kDenominator : 1;

    const Fraction res = {data.x + (kNumeratorRes == 0 && kNumerator != 0), kNumeratorRes, kDenominatorRes};

    return res;
}

size_t gcd(size_t a, size_t b) {
    while (b) {
        size_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

size_t lcm(size_t a, size_t b) {
    return (a * b) / gcd(a, b);
}

Fraction SumOfFractions(const Fraction* a, const Fraction* b) {
    const size_t kMainDenominator = lcm(a->denominator, b->denominator);
    const size_t kAKoef = kMainDenominator / a->denominator;
    const size_t kBKoef = kMainDenominator / b->denominator;

    const size_t kMainNumerator = a->numerator * kAKoef + b->numerator * kBKoef;

    const Fraction res = {kMainNumerator / kMainDenominator + a->whole + b->whole, kMainNumerator % kMainDenominator, kMainDenominator};

    return res;
}

char* CountFractionByPresition(const Fraction* drob, size_t presition) {
    char* res = (char*)malloc(sizeof(char) * presition);

    if (!res) return NULL;

    const size_t kMod = 10;
    size_t numerator = drob->numerator;
    
    for (size_t i = 0; i < presition; ++i) {
        numerator *= kMod;
        size_t whole = numerator / drob->denominator;
        res[i] = whole;
        if (whole)
            numerator %= drob->denominator;
    }

    return res;
}

size_t Log10SizeT(size_t n) {
    const size_t kMod = 10;
    if (!(n / kMod)) {
        return 0;
    }
    for (size_t i = 1; ; ++i) {
        size_t tmp = n / kMod;
        if (tmp >= 1 && tmp <= 9) {
            return i;
        }
        n = tmp;
    }
}

int IsPeriodZero(const char* period_start, size_t period_len) {
    const size_t kMod = 10;

    size_t period = 0;
    for (size_t i = 0; i < period_len; ++i) {
        period *= kMod;
        period += period_start[i];
    }

    return period == 0ul;
}

char* HighLinghtPeriod(const Fraction* drob, char* dec_frac, size_t presition) {
    if (!dec_frac) return NULL;

    size_t period_id = 0;
    size_t period_len = 0;
    int is_finded_period = 0;
    for (size_t i = 1; i < presition; ++i) {
        if (is_finded_period) {
            break;
        }
        for (size_t j = 0; j < i; ++j) {
            if (dec_frac[i] != dec_frac[j]) continue;

            int has_period = 1;
            for (size_t k = 0; k < presition - i; ++k) {
                if (dec_frac[i + k] != dec_frac[j + k]) {
                    has_period = 0;
                    break;
                }
            }
            if (has_period) {
                period_id = j;
                is_finded_period = 1;
                period_len = i - j;
                break;
            }
        }
    }

    char* res = NULL;
    if (!(res = (char*)malloc(sizeof(char) * presition))) {
        free(dec_frac);
        return NULL;
    }

    sprintf(res, "%lld.", drob->whole);
    const size_t kWholeSize = Log10SizeT(drob->whole) + 2ul;

    for (size_t i = 0; i < period_id; ++i) {
        res[i + kWholeSize] = dec_frac[i] + '0';
    }
    if (!IsPeriodZero(dec_frac + period_id, period_len)) {
        res[period_id + kWholeSize] = '(';
        for (size_t i = 0; i < period_len; ++i) {
            res[i + kWholeSize + period_id + 1] = dec_frac[period_id + i] + '0';
        }
        res[period_id + kWholeSize + 2 + period_len] = '\0';
        res[period_id + kWholeSize + 1 + period_len] = ')';
    } else {
        res[period_id + kWholeSize] = '\0';
    }

    free(dec_frac);

    return res;
}

char* ConvertNonPeriodFraction(const Fraction* drob) {
    const size_t kSize = 100;
    
    char* res = NULL;
    if (!(res = (char*)malloc(sizeof(char) * kSize))) return NULL;

    sprintf(res, "%lld", drob->whole);

    if (drob->numerator == 0) return res;

    const size_t kWholeSize = Log10SizeT(drob->whole) + 1;
    sprintf(res + kWholeSize, ".%lld", drob->numerator);

    return res;
}

int HasFractionPeriod(const Fraction* drob) {
    return (drob->denominator % 9) == 0 && drob->numerator != 0;
}

void PrintFractions(char* res, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%d", res[i]);
    }
} 

char* ConvertFraction2Str(const Fraction* drob) {
    const size_t kNumberSize = 100;

    return (HasFractionPeriod(drob)) ? HighLinghtPeriod(drob, CountFractionByPresition(drob, kNumberSize), kNumberSize) : ConvertNonPeriodFraction(drob);
}

