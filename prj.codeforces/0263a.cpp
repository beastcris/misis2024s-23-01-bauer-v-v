#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>



int main() {
	int iidx = 0, jidx = 0;
	std::vector <std::vector <int>> f(5, std::vector <int>(5));
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			std::cin >> f[i][j];
			if (f[i][j] == 1) {
				iidx = i;
				jidx = j;
			}
		}
	}

	std::cout << abs(iidx - 2) + abs(jidx - 2);
}

