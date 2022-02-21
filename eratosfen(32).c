#include <stdio.h>
#include <stdlib.h>
#define N 32
typedef long long ll;
const unsigned int ull = 4294967295; //9223372036854775807 == 2 ^ 63 - 1

ll * flags, ull_bit_mask[N + 5] = {};



int main() {
	ll l = 1;
	for(int i = 0; i < N; i ++) {
		ull_bit_mask[i] = ull - l;
		l <<= 1;
	}
	int n;
	scanf("%d", &n);
	int ost = n % N, flag = n / N;
	flags = (ll *)malloc((flag + 1)* sizeof(ll));
	for(int i = 0; i <= flag; i ++) {
		flags[i] = ull;
	}

	for(int i = N - 1; i > ost; i --) {
		flags[flag] &= ull_bit_mask[i];
	}

	for(int i = 2; i * i <= n; i ++) {
		if(flags[i / N] & ull_bit_mask[i % N]) {
			for(int j = i * i; j <= n; j += i) {
				flags[j / N] &= ull_bit_mask[j % N];
			}
		}
	}
	int k = 0;
	for(int i = 0; i <= flag; i ++) {
		for(int j = 0; j < N; j ++) {
			k += flags[i] % 2;
			flags[i] >>= 1;
		}
	}
	printf("%d", k - 2);
	free(flags);
	return 0;
}
