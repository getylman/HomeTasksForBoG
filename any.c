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
		s -> size *= 2;
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
			printf("%d ", s -> a[i]);
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
	int n, k;
	char A[40];
	scanf("%d", &n);
	scanf("%s", A);
	scanf("%d", &k);
	int len = 0;
	while(*(A + len) != '\0') {
		len ++;
	}
	//printf("%d\n\n", len);
	unsigned long long L1 = 0, l1 = 1;
	for(int i = 0; i < len ; i ++) {
		char c = A[len - i - 1];
		if(c > 47 && c < 59) {
			L1 += l1 * (c - 48);
		}
		else {
			L1 += l1 * (c - 55);
		}
		l1 *= n;
	}
	if(L1 == 0) {
		printf("0");
		return 0;
	}
	//printf("%llX", L1);
	char C[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	struct Stack * S = stack_create(50);
	while(L1) {
		stack_push(S, C[L1 % k]);
		L1 /= k;
	}
	while(!stack_is_empty(S)) {
		printf("%c", stack_get(S));
		stack_pop(S);
	}
	stack_destroy(S);
	return 0;
}
