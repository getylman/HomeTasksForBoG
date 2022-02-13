#include <stdio.h>
#include <stdlib.h>



typedef long long ll;
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
			printf("%c ", s -> a[i]);
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
	char A[1005], B[1005];
	scanf("%s%s", A, B);
	struct Stack * S = stack_create(1009);
	int lenA = 0;
	while(*(A + lenA) != '\0') {
		lenA ++;
	}
	int lenB = 0;
	while(*(B + lenB) != '\0') {
		lenB ++;
	}

	int MaxL = (lenA > lenB) ? (lenA) : (lenB);
	int c = 0;
	for(int i = 0; i < MaxL; i ++) {
		int l = 0;
		if(lenA - i > 0) {
			if(A[lenA - i - 1] == '0') {
				l += 0;
			}
			else if(A[lenA - i - 1] == '1') {
				l += 1;
			}
			else if(A[lenA - i - 1] == '$') {
				l += -1;
			}
		}
		if(lenB - i > 0) {
			if(B[lenB - i - 1] == '0') {
				l += 0;
			}
			else if(B[lenB - i - 1] == '1') {
				l += 1;
			}
			else if(B[lenB - i - 1] == '$') {
				l += -1;
			}
		}
		l += c;
		char putting_char;
		if(l == 3) {
			c = 1;
			putting_char = '0';
		}
		else if(l == -3) {
			c = -1;
			putting_char = '0';
		}
		else if(l == 0) {
			c = 0;
			putting_char = '0';
		}
		else if(l == 2) {
			c = 1;
			putting_char = '$';
		}
		else if(l == -2) {
			c = -1;
			putting_char = '1';
		}
		else if(l == 1) {
			c = 0;
			putting_char = '1';
		}
		else if(l == -1) {
			c = 0;
			putting_char = '$';
		}
		stack_push(S, putting_char);
	}
	if(c) {
		if(c == -1) {
			stack_push(S, '$');
		}
		else if(c == 1) {
			stack_push(S, '1');
		}
	}
	int ok = 0;
	while(!stack_is_empty(S)) {
		char l = stack_get(S);
		if(l == '$' || l == '1') {
			ok ++;
			printf("%c", l);
		}
		else if(l == '0' && ok) {
			printf("%c", l);
		}
		stack_pop(S);
	}
	if(!ok) {
		printf("0");
	}
	stack_destroy(S);
	//printf("%lld", a);
	return 0;
}




/*
ll F(char * A) {
	ll a = 0;
	int len = 0;
	while(*(A + len) != '\0') {
		len ++;
	}
	int ok = 0, it = 0;
	for(int i = 0; i < len; i ++) {
		if(A[i] != '0') {
			ok ++;
		}
		if(ok == 1) {
			it = i;
			break;
		}
	}
	ll l = 1;
	for(int i = len - 1; i >= it; i --) {
		int b = (A[i] == '$') ? (-1) : ((A[i] == '0') ? (0) : (1));
		a += b * l;
		l *= 3;
	}
	return a * ok;
}*/
