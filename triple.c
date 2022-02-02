#include <stdio.h>


int main() {
	long long n, k = 0, o = 1;
	scanf("%lld", &n);
	while(n) {
		k += o * (n % 10);
		o *= 3;
		n /= 10;
	}
	printf("%lld", k);
	return 0;
}
