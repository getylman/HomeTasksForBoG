#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned long long ll;
#define N 150
#define NN 1400

typedef struct {
	char X[N], Y[N], Z[N], sym, maxC;
}XYZ;

int A[NN] = {};
int stop_bool = 0;
ll NUM = 9223372036854775807;

ll tr(char * s, int mod) {
	ll a = 0, l = 1;
	int len = 0;
	while(*(s + len) != '\0') {
		++ len;
	}
	for(int i = len - 1; i >= 0; i --) {
		if(NUM / l < (ll)mod) {
			stop_bool = 1;
		}
		a += l * A[(int)s[i]];
		l *= A[mod];
	}
	return a;
}



int main() {
	int I = 0;
	for(int i = 48; i < 58; i ++) {
		A[i] = I ++;
	}
	for(int i = 97; i < NN; i ++) {
		A[i] = I ++;
	}
	int n;
	XYZ S[1009] = {};
	scanf("%d", &n);
	char max_mod = 0;
	for(int i = 0; i < n; i ++) {
		char s[300] = {};
		scanf("%s", s);
		int it = 0, u = 0, id = 0;
		char mxC = 0;
		while(*(s + it) != '\0') {
			if(s[it] == '+' || s[it] == '*') {
				u = 1;
				S[i].X[id] = '\0';
				id = 0;
				S[i].sym = s[it];
				it ++;
				continue;
			}
			if(s[it] == '=') {
				u = 2;
				S[i].Y[id] = '\0';
				id = 0;
				it ++;
				continue;
			}
			if(s[it] > mxC) {
				mxC = s[it];
			}
			if(u == 0) {
				S[i].X[id ++] = s[it];
			}
			else if(u == 1) {
				S[i].Y[id ++] = s[it];
			}
			else if(u == 2) {
				S[i].Z[id ++] = s[it];
			}
			it ++;
		}
		S[i].Z[id] = '\0';
		if(mxC == '0') {
			mxC ++;
		}
		mxC ++;
		S[i].maxC = mxC;
		if(max_mod < mxC) {
			max_mod = mxC;
		}
	}
	int counter_of_true = 0, true_mod = 0;
	for(int i = max_mod; i < NN; i ++) {
		if(i > 57 && i < 97) {
			continue;
		}
		int kk = 0, ok = 0;
		for(int j = 0; j < n; j ++) {
			ll x = tr(S[j].X, i);
			ll y = tr(S[j].Y, i);
			ll z = tr(S[j].Z, i);
			if(stop_bool) {
				ok = 1;
				break;
			}
			ll th = 0;
			if(S[j].sym == '*') {
				th = x * y;
			}
			else if(S[j].sym == '+') {
				th = x + y;
			}
			if(th == z) {
				++ kk;
			}
		}
		if(ok) {
			break;
		}
		if(kk == n) {
			true_mod = i;
			counter_of_true ++;
		}
	}
	if(counter_of_true == 0) {
		printf("0");
	}
	else if(counter_of_true == 1) {
		printf("%d", A[true_mod]);
	}
	else {
		printf("-1");
	}

	return 0;
}

