#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
 
int main() {
	int t;
	std::cin >> t;
	for (t; t > 0; --t) {
		int n = 0;
		int k = 0;
		int x = 0;
		int y = 0;
		std::cin >> n >> k >> x >> y;
		--x;
		--y;
		int idxline = (y + x) % n;
		for (int i = 0; i < n; ++i) {
			if (i > 0) {
				if (idxline - 1 < 0) {
					idxline = n - 1;
				}
				else {
					--idxline;
				}
				idxline -= k * (idxline / k);
			}
			for (int j = 0; j < n; ++j) {
				if (abs(idxline - j) % k == 0) {
					std::cout << "X";
				}
				else {
					std::cout << ".";
				}
			}
			std::cout << std::endl;
		}
	}
}
