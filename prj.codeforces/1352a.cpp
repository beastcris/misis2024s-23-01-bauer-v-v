#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>



int main() {
	int num, t;
	
	std::cin >> t;
	for (t; t > 0; --t) {
		std::cin >> num;
		int cnt = 0;
		std::vector <int> nums;
		while (num!=0) {
			if ((num % 10) * pow(10, cnt) != 0) {
				nums.push_back((num % 10) * pow(10, cnt));
			}
			num /= 10;
			++cnt;
		}
		std::cout << nums.size() << std::endl;
		for (int i=0; i < nums.size(); ++i) {
			std::cout << nums[i] << " ";
			
		}
		std::cout << std::endl;
	}
	
}

