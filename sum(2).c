#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long double D;

int cmp(const void* a, const void* b) {
	return ceil(*(const D*)a - *(const D*)b);
}


int  main() {
	D a;
	int it = 0, N = 10000069;
	D *A = (D *)malloc(sizeof(D) * N);
	while(scanf("%Lf", &a) != EOF) {
		A[it ++] = a;
	}
	qsort(A, it, sizeof(D), cmp);
	D s = 0;
	for(int i = 0; i < it; i ++) {
		s += A[i];
	}
	printf("%.20Lf", s);
	return 0;
}
s
