#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
	char * z = argv[1];
	double x;
	int y, len = 0;
	scanf("%lf%x", &x, &y);
	while(*(z + len) != '\0') {
		if(z[len] > 90) {
			z[len] -= 32;
		}
		len ++;
	}
	int Z = 0, l = 1;
	for(int i = len - 1; i >= 0; i --) {
		int o = 0;
		if(z[i] > 47 && z[i] < 58) {
			o = z[i] - 48;
		}
		else {
			o = z[i] - 55;
		}
		Z += l * o;
		l *= 27;
	}
	x += Z;
	x += y;
	printf("%.03lf", x);
	return 0;
	argc ++;
}
