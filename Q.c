#include <stdio.h>
#include <stdlib.h>


int to_mod(int n, int m) {
	long long X = 1;
	X *= (long long)n * (long long)n;
	int ok = 1;
	while(n && X) {
		if((n % m) != (X % m)) {
			ok = 0;
			break;
		}
		n /= m;
		X /= m;
	}
	return ok;
}



int main() {
	int n, MaxVal = 0;
	scanf("%d", &n);
	int m = n * n * n;
	for(int i = 0; i < m; i ++) {
		if(to_mod(i, m) && i > MaxVal) {
			MaxVal = i;
		}
	}
	printf("%d", MaxVal);

	return 0;
}

