#include <stdio.h>
#include <stdlib.h>


typedef char Data;

struct Stack {
	int n;
	int size;
	Data * a;
};



struct Stack * stack_create(int size) {
	struct Stack * s = NULL;
	s = malloc(sizeof(struct Stack));
	if(s == NULL || size == 0) {
		exit(-1);
	}
	s -> n = 0;
	s -> size = size;
	s -> a = (Data*)malloc(size * sizeof(Data));
	if(s -> a == NULL) {
		exit(-1);
	}
	return s;
}

void stack_push(struct Stack * s, Data x) {
	if (s -> size == s -> n + 1) {
		s -> size ++;
		s -> a = (Data*)realloc(s -> a, s -> size * sizeof(Data));
	}
	s -> a[s -> n ++] = x;
}

Data stack_pop(struct Stack * s) {
	return s -> a[-- (s -> n)];
}

Data stack_get(struct Stack * s) {
	return s -> a[(s -> n) - 1];
}

int stack_is_empty(struct Stack * s) {
	return !(s -> n);
}

void stack_print(struct Stack * s) {
	if(s -> n) {
		for(int i = 0; i < s -> n; i ++) {
			printf("%d ", s -> a[s -> n - i]);
		}
		printf("\n");
	}
	else {
		printf("Empty stack\n");
	}
}

int stack_size(struct Stack * s) {
	return s -> n;
}

void stack_clear(struct Stack * s) {
	s -> n = 0;
}

void stack_destroy(struct Stack* s) {
	free(s -> a);
	free(s);
}




int main() {
	const int N = 1005;
	char *a, *b;
	a = (char*)malloc(sizeof(char) * N);
	b = (char*)malloc(sizeof(char) * N);
	scanf("%s", a);
	scanf("%s", b);
	int lena = 0, lenb = 0;
	while(*(a + lena) != '\0') {
		++ lena;
	}
	while(*(b + lenb) != '\0') {
		++ lenb;
	}
	char *A, *B;
	A = (char*)malloc(sizeof(char) * N);
	B = (char*)malloc(sizeof(char) * N);
	int it = 0, ok = 0;
	int lenA = 0, lenB = 0;
	for(int i = 0; i < lena; i ++) {
		if(a[i] != '0')
			++ ok;
		if(ok) {
			A[it ++] = a[i] - 48;
		}
	}
	if(ok == 0) {
		A[0] = 0;
		A[1] = '\0';
		lenA = 1;
	}
	else {
		A[it] = '\0';
		lenA = it;
	}

	ok = 0;
	it = 0;
	for(int i = 0; i < lenb; i ++) {
		if(b[i] != '0')
			++ ok;
		if(ok) {
			B[it ++] = b[i] - 48;
		}
	}
	if(ok == 0) {
		B[0] = 0;
		B[1] = '\0';
		lenB = 1;
	}
	else {
		B[it] = '\0';
		lenB = it;
	}
	free(a);
	free(b);
	int MaxL = (lenA > lenB) ? (lenA) : (lenB);
	//printf("%s\n%s", A, B);
	char p = 0;
	struct Stack * S = stack_create(MaxL + 1);
	for(int i = 0; i < MaxL; i ++) {
		char y = 0;
		if(lenA - i > 0) {
			y += A[lenA - i - 1];
		}
		if(lenB - i > 0) {
			y += B[lenB - i - 1];
		}
		y += p;
		p = y / 2;
		stack_push(S, y % 2);
	}
	if(p) {
		stack_push(S, p);
	}
	while(!stack_is_empty(S)) {
		printf("%d", stack_get(S));
		stack_pop(S);
	}
	stack_destroy(S);
	free(A);
	free(B);
	return 0;
}
