#include <stdio.h>

int main() {
    int a[9] = {};
    int r, r1 = 4, b, c, mask = 255;  
#ifdef REGISTERS
    r1 = REGISTERS;
#endif
    while (1) {
        scanf("%d", &r);
        if (!r) {
            return 0;
        }
        switch(r) {
            case 1:
                scanf("%d %d", &b, &c);
                if (b > r1 + 4 || c > r1 + 4) {
                    printf("-1");
                    return 0;
                }
                a[b] += a[c];
                a[b] &= mask;
                break;
            case 2:
                scanf("%d %d", &b, &c);
                if (b > r1 + 4 || c > r1 + 4) {
                    printf("-1");
                    return 0;
                }
                a[b] -= a[c];
                a[b] &= mask;
                break;
            case 3:
                scanf("%d %d", &b, &c);
                if (b > r1 + 4) {
                    printf("-1");
                    return 0;
                }
                a[b] = c;
                break;
            case 4:
                for (int i = 5; i <= 4 + r1; ++i) {
                    printf("%d ", a[i]);
                }
                printf("\n");
        }
    }
}
