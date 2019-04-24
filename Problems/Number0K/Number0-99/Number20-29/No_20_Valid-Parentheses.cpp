//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//
//Note that an empty string is also considered valid.
//
//Example 1:
//
//Input: "()"
//	Output : true
//
//	Example 2 :
//
//	Input : "()[]{}"
//	Output : true
//
//	Example 3 :
//
//	Input : "(]"
//	Output : false
//
//	Example 4 :
//
//	Input : "([)]"
//	Output : false
//
//	Example 5 :
//
//	Input : "{[]}"
//	Output : true



//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
//Memory Usage : 8.6 MB, less than 99.75% of C++ online submissions for Valid Parentheses.

class Solution {
public:
	map<char, char> par = {
			{'(', ')'},
			{'[', ']'},
			{'{', '}'},
			{')', '('},
			{']', '['},
			{'}', '{'},
	};
	bool isValid(string s) {
		vector<char> vec_store;
		if (s.length() == 0) { return true; }
		else if (s.length() % 2 != 0) { return false; }
		else {
			string::iterator it_l = s.begin();
			while (it_l != s.end()) {
				switch (*it_l)
				{
				case '(':case '[':case '{':
				case ')':case ']':case '}':
					break;
				default:
					return false;
				}
				if (vec_store.size() > 0 && vec_store.back() == par[*it_l]) { vec_store.pop_back(); }
				else { vec_store.push_back(*it_l); }
				++it_l;
			}

		}

		if (vec_store.size() > 0) { return false; }
		return true;
	}
};