#include <stdio.h>

typedef long long ll;

int A[1030][1030] = {};
int B[1030][1030] = {};
int cache[1030][1030] = {};

int __gcd(int a, int b) {
    if(cache[a][b] != 0) return cache[a][b];
    int r = 0;
    if(b == 0) r = a;
    else if(b == 1 || a == 1) r = 1;
    else r = __gcd(b, a % b);
    cache[a][b] = r;
    cache[b][a] = r;
    return r;
}

int main() {
    int n, d, k = 0;
    scanf("%d%d", &n, &d);
    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j <= i; j ++) {
            B[i][j] = (int)__gcd(n - i + 1, n - j + 1);
            B[j][i] = B[i][j];
        }
    }

    for(int i = 1; i < n; i ++) {
        for(int j = 1; j <= i; j ++) {
            A[n - i][n - j] = B[i][j];
            A[n - j][n - i] = B[i][j];
        }
    }

    for(int i = 0; i < n; i ++) {
        A[0][i] = 1;
        A[i][0] = 1;
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            ll s = 0;
            for(int k1 = 0; k1 < n; k1 ++) {
                s += A[i][k1] * B[j][k1];
            }
            k += (!(s % d));
        }
    }

    printf("%d", k);
    return 0;
}
