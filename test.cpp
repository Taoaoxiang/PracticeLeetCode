#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		int sign = 1;
		int rtn;
		int tmp_i = x;
		long li=0;
		if (x < 0) { 
			sign *= -1;
			tmp_i *= -1;
		}
		else if (x == 0) { return 0; }
		int digit = pow(10, 9);
		int digit2=1;
		while (tmp_i/digit == 0) {
			digit /= 10;
		}
		while (digit != 0) {
			li += (tmp_i / digit)*digit2;
			tmp_i = tmp_i % digit;
			digit /= 10;
			digit2 *= 10;
		}
		li *= sign;
		if (li > (pow(2, 31) - 1) || li < (pow(-2, 31))) { return 0; }
		else { rtn = li; }
		//cout << x << '\n'<<li << endl;
		return rtn;
	}
};

int main() {

	string s;
	int x;
	s = "PAYPALISHIRING";
	x = 123;
	int ret = Solution().reverse(x);

	cout << ret << endl;

	std::cout << "Wuzup world!" << std::endl;
	return 0;
}