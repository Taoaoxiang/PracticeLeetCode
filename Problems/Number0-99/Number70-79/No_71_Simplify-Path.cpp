//Given an absolute path for a file(Unix - style), simplify it.Or in other words, convert it to the canonical path.
//
//In a UNIX - style file system, a period.refers to the current directory.Furthermore, a double period ..moves the directory up a level.For more information, see: Absolute path vs relative path in Linux / Unix
//
//Note that the returned canonical path must always begin with a slash / , and there must be only a single slash / between two directory names.The last directory name(if it exists) must not end with a trailing / .Also, the canonical path must be the shortest string representing the absolute path.
//
//
//
//Example 1:
//
//Input: "/home/"
//	Output : "/home"
//	Explanation : Note that there is no trailing slash after the last directory name.
//
//	Example 2 :
//
//	Input : "/../"
//	Output : "/"
//	Explanation : Going one level up from the root directory is a no - op, as the root level is the highest level you can go.
//
//	Example 3 :
//
//	Input : "/home//foo/"
//	Output : "/home/foo"
//	Explanation : In the canonical path, multiple consecutive slashes are replaced by a single one.
//
//	Example 4 :
//
//	Input : "/a/./b/../../c/"
//	Output : "/c"
//
//	Example 5 :
//
//	Input : "/a/../../b/../c//.//"
//	Output : "/c"
//
//	Example 6 :
//
//	Input : "/a//b////c/d//././/.."
//	Output : "/a/b/c"
//
//
//Runtime: 8 ms, faster than 99.93% of C++ online submissions for Simplify Path.
//Memory Usage : 10.2 MB, less than 98.77% of C++ online submissions for Simplify Path.

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> vec;
		path += "/";
		int iLast = 0;
		int iFind = path.find('/', iLast + 1);
		while (iFind != string::npos) {
			if (iFind != iLast + 1) {
				string s = path.substr(iLast + 1, iFind - iLast - 1);
				if (s == ".") {}
				else if (s == "..") { if (vec.size() != 0) { vec.pop_back(); } }
				else { vec.push_back(s); }
			}
			iLast = iFind;
			if (iLast + 1 >= path.size()) { break; }
			iFind = path.find('/', iLast + 1);
		}
		string rtn = "";
		if (vec.size() == 0) { return "/"; }
		for (int i = 0; i < vec.size(); ++i) { rtn += ("/" + vec[i]); }

		return rtn;
	}
};