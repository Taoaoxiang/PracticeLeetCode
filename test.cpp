#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;

		vector<string> vec_all;
		for (int i = 0; i != numRows;++i) {
			string tmp;
			vec_all.push_back(tmp);
		}
		for (int i = 0; i != s.size();++i) {
			int serie = 2 * numRows - 2;
			int ori_row = i % (serie);
			int fin_row;
				if (ori_row < numRows) {
					fin_row = ori_row;
				}
				else {
					fin_row = serie - ori_row;
				}
				vec_all[fin_row].push_back(s[i]);
		}
		string rtn;
		for (int i = 0; i != numRows;++i) {
			//cout << "T1: "<< vec_all[i] << endl;
			rtn += vec_all[i];
		}
		return rtn;
	}
};

int main() {

	string s;
	int numRows;
	s = "PAYPALISHIRING";
	numRows = 4;
	string ret = Solution().convert(s, numRows);

	string out = (ret);
	cout << out << endl;

	std::cout << "Wuzup world!" << std::endl;
	return 0;
}