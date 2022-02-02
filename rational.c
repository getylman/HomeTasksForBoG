#include <stdio.h>
#include <stdlib.h>





int main() {
	char A[1000];
	scanf("%s", A);
	int point = 0, len = 0;
	while(*(A + len) != '\0') {
		if(A[len] == '.') {
			point = len;
		}
		len ++;
	}
	if(point) {
		unsigned long long a = 0, l = 1, b = 0;
		for(int i = 0; i < point; i ++) {
			a += l * (A[point - i - 1] - 48);
			l *= 2;
		}
		l = 1;

		for(int i = len - 1; i > point; i --) {
			//printf("%llu\t", b);
			b += l * (A[i] - 48);
			//printf("%llu\n", b);
			l *= 2;
		}
		double c = a + ((double)b / l);
		printf("%.12lf", c);
	}
	else {
		unsigned long long a = 0, l = 1;
		for(int i = 0; i < len; i ++) {
			a += l * (A[len - i - 1] - 48);
			l *= 2;
		}
		printf("%llu.000000000000", a);
	}
	return 0;
}
