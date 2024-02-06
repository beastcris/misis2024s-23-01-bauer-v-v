#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>



int main() {
	int a = 0;
	std::cin >> a;
	if (a % 2 == 0 && a!=2) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
}

