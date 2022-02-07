#include <stdio.h>
#include <stdlib.h>



int main() {
	char s[50];
	scanf("%s", s);
	int len = 0;
	while(*(s + len) != '\0') {
		len ++;
	}

	int A[100] = {};
	A[(int)'I'] = 1;
	A[(int)'V'] = 5;
	A[(int)'X'] = 10;
	A[(int)'L'] = 50;
	A[(int)'C'] = 100;
	A[(int)'D'] = 500;
	A[(int)'M'] = 1000;
	int num = A[(int)s[len - 1]];
	for(int i = len - 2; i >= 0; i --) {
		if(A[(int)s[i]] < A[(int)s[i + 1]]) {
			num -= A[(int)s[i]];
		}
		else {
			num += A[(int)s[i]];
		}
	}
	printf("%d", num);

	return 0;
}
