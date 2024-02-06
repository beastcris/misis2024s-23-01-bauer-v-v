#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>



int main() {
	int a, fir,sec,third, four;
	std::cin >> a;
	bool flag = true;
	while (flag) {
		++a;
		fir = a / 1000;
		sec = (a%1000) / 100;
		third = ((a % 1000) % 100) / 10;
		four = a % 10;
		if (fir != sec && fir != third && fir != four  && sec != third && sec != four && third != four) {
			std::cout << a;
			flag = false;
		}
	}
}

