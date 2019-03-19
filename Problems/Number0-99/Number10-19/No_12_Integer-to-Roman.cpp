//Roman numerals are represented by seven different symbols : I, V, X, L, C, D and M.
//
//Symbol       Value
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//
//For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.
//
//Roman numerals are usually written largest to smallest from left to right.However, the numeral for four is not IIII.Instead, the number four is written as IV.Because the one is before the five we subtract it making four.The same principle applies to the number nine, which is written as IX.There are six instances where subtraction is used :
//
//I can be placed before V(5) and X(10) to make 4 and 9.
//X can be placed before L(50) and C(100) to make 40 and 90.
//C can be placed before D(500) and M(1000) to make 400 and 900.
//
//Given an integer, convert it to a roman numeral.Input is guaranteed to be within the range from 1 to 3999.
//

// This is slow solution?
// LOL, because I generated the entire table from 1 to 3999.
// I'm pretty okay with this solution.
class Solution {
public:
	// Range: [1 ~ 3999]
	vector<vector <string>> RomanNumTable() {
		vector<vector <string>> rtn;
		int ctrl = 0;
		int maxNum = 3999;
		vector<char> vec1 = { 'I','X','C','M' };
		vector<char> vec5 = { 'V','L','D' };
		while (maxNum) {
			vector<string> vec_tmp;
			for (int i = 0; i <= maxNum % 10;++i) {
				string s_num;
				switch (i) {
				case 0: case 1:	case 2: case 3:
					s_num = string(i, vec1[ctrl]);
					break;
				case 4:
					s_num += vec1[ctrl];
					s_num += vec5[ctrl];
					break;
				case 5: case 6: case 7: case 8:
					s_num += vec5[ctrl];
					s_num += string(i - 5, vec1[ctrl]);
					break;
				case 9:
					s_num += (vec1[ctrl]);
					s_num += vec1[ctrl + 1];
					break;
				default:
					break;
				}
				vec_tmp.push_back(s_num);
			}
			++ctrl;
			maxNum /= 10;
			rtn.push_back(vec_tmp);
		}
		return rtn;
	}

	string intToRoman(int num) {
		vector<vector <string>> vecTable = RomanNumTable();
		int tmp = num;
		int ctrl = 0;
		string rtn = "";
		while (tmp != 0) {
			rtn = vecTable[ctrl++][tmp % 10] + rtn;
			tmp = tmp / 10;
		}
		//for (int i = 0; i != vecTable.size();++i) {
		//	cout << "Group " << i << "=>" << endl;
		//	for (int b = 0; b != vecTable[i].size();++b) {
		//		cout << " " << i << " " << b  << ": " << vecTable[i][b] << endl;
		//	}
		//}
		return rtn;
	}
};