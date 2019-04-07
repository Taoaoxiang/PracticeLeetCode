#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <functional>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> vec;
		path += "/";
		int iLast = 0;
		int iFind = path.find('/', iLast+1);
		while (iFind != string::npos) {
			if (iFind != iLast + 1) { 
				string s = path.substr(iLast + 1, iFind - iLast - 1);
				if (s == ".") {}
				else if (s == "..") { if (vec.size() != 0) { vec.pop_back(); } }
				else { vec.push_back(s); }
			}
			iLast = iFind;
			if (iLast + 1 >= path.size()) { break; }
			iFind = path.find('/', iLast+1);
		}
		string rtn = "";
		if (vec.size() == 0) { return "/"; }
		for (int i = 0; i < vec.size(); ++i) { rtn += ("/" + vec[i]); }

		return rtn;
	}
};


int main() {

	string path = "/home/";
	path = "/a//b////c/d//././/..";

	string ret = Solution().simplifyPath(path);

	string out = (ret);
	cout << out << endl;


	std::cout << "Wuzup world!" << std::endl;
	return 0;
}