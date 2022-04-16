#include <iostream>
#include <vector>
#include <utility>
   
std::vector<std::pair<int, int>> v; 
int k;

void f(int x, int col) {
	if (!v[x].second) {
		v[x].second = col;
		f(v[x].first, col);
	}
	else {
		if (v[x].second == col) 
			k ++;
		return;
	}
}

   
main() {
	int n;
	std::cin >> n;
	v.resize(n + 1);
	for (int i = 1, a = 0; i <= n; i ++) {
		std::cin >> a;
		v[i] = std::make_pair(a, 0);
	}
	for (int i = 1; i < (int)v.size(); i ++) {
		f(i, i);
	}
	std::cout << k;
}
