//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
//Note:
//
//    Division between two integers should truncate toward zero.
//    The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.
//
//Example 1:
//
//Input: ["2", "1", "+", "3", "*"]
//Output: 9
//Explanation: ((2 + 1) * 3) = 9
//
//Example 2:
//
//Input: ["4", "13", "5", "/", "+"]
//Output: 6
//Explanation: (4 + (13 / 5)) = 6
//
//Example 3:
//
//Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
//Output: 22
//Explanation: 
//  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22

//Runtime: 16 ms, faster than 92.40% of C++ online submissions for Evaluate Reverse Polish Notation.
//Memory Usage : 11.8 MB, less than 10.89% of C++ online submissions for Evaluate Reverse Polish Notation.

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> sS;
		for (int i = 0; i < tokens.size(); ++i) {
			string s = tokens[i];
			int i1, i2;
			switch (s.back())
			{
			case '+':
				i2 = sS.top();
				sS.pop();
				i1 = sS.top();
				sS.pop();
				sS.push(i1 + i2);
				break;
			case '-':
				i2 = sS.top();
				sS.pop();
				i1 = sS.top();
				sS.pop();
				sS.push(i1 - i2);
				break;
			case '*':
				i2 = sS.top();
				sS.pop();
				i1 = sS.top();
				sS.pop();
				sS.push(i1 * i2);
				break;
			case '/':
				i2 = sS.top();
				sS.pop();
				i1 = sS.top();
				sS.pop();
				sS.push(i1 / i2);
				break;
			default:
				sS.push(stoi(s));
				break;
			}
		}
		return sS.top();
	}
};

//Runtime: 1404 ms, faster than 6.00% of C++ online submissions for Evaluate Reverse Polish Notation.
//Memory Usage : 11.8 MB, less than 10.89% of C++ online submissions for Evaluate Reverse Polish Notation.

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> sS;
		while (tokens.size() > 0) {
			string s = tokens[0];
			tokens.erase(tokens.begin());
			char c = s.back();
			int i1, i2;
			switch (c)
			{
			case '+':
				i2 = sS.top();
				sS.pop();
				i1 = sS.top();
				sS.pop();
				sS.push(i1 + i2);
				break;
			case '-':
				i2 = sS.top();
				sS.pop();
				i1 = sS.top();
				sS.pop();
				sS.push(i1 - i2);
				break;
			case '*':
				i2 = sS.top();
				sS.pop();
				i1 = sS.top();
				sS.pop();
				sS.push(i1 * i2);
				break;
			case '/':
				i2 = sS.top();
				sS.pop();
				i1 = sS.top();
				sS.pop();
				sS.push(i1 / i2);
				break;
			default:
				sS.push(stoi(s));
				break;
			}
		}
		return sS.top();
	}
};