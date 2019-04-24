//Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
//
//You have the following 3 operations permitted on a word :
//
//Insert a character
//Delete a character
//Replace a character
//
//Example 1:
//
//Input: word1 = "horse", word2 = "ros"
//	Output : 3
//	Explanation :
//	horse->rorse(replace 'h' with 'r')
//	rorse->rose(remove 'r')
//	rose->ros(remove 'e')
//
//	Example 2 :
//
//	Input : word1 = "intention", word2 = "execution"
//	Output : 5
//	Explanation :
//	intention->inention(remove 't')
//	inention->enention(replace 'i' with 'e')
//	enention->exention(replace 'n' with 'x')
//	exention->exection(replace 'n' with 'c')
//	exection->execution(insert 'u')
//


//Runtime: 16 ms, faster than 77.79% of C++ online submissions for Edit Distance.
//Memory Usage : 11.2 MB, less than 32.53% of C++ online submissions for Edit Distance.

// if the same char, then v[i1][i2] equals to upper-left/top-left v[i1-1][i2-1]
// if not the same, then v[i1][i2] will pick the minimum of v[i1-1][i2-1], v[i1][i2-1], and v[i1-1][i2], and +1
class Solution {
public:
	int min3(int i1, int i2, int i3) {
		if (i1 <= i2) {
			if (i1 <= i3) { return i1; }
			else { return i3; }
		}
		else {
			if (i2 <= i3) { return i2; }
			else { return i3; }
		}
	}

	int minDistance(string word1, string word2) {
		int wS1 = word1.size(), wS2 = word2.size();
		if (wS1 == 0 && wS2 == 0) { return 0; }
		else if (wS1 == 0 && wS2 != 0) { return wS2; }
		else if (wS1 != 0 && wS2 == 0) { return wS1; }
		else {
			vector<vector<int>> vec(wS1 + 1, vector<int>(wS2 + 1, 0));
			for (int i1 = 0; i1 < wS1 + 1; ++i1) {
				for (int i2 = 0; i2 < wS2 + 1; ++i2) {
					if (i1 == 0 && i2 == 0) { vec[i1][i2] = 0; }
					else if (i1 == 0 && i2 != 0) { vec[i1][i2] = i2; }
					else if (i1 != 0 && i2 == 0) { vec[i1][i2] = i1; }
					else {
						if (word1[i1 - 1] == word2[i2 - 1]) { vec[i1][i2] = vec[i1 - 1][i2 - 1]; }
						else { vec[i1][i2] = min3(vec[i1 - 1][i2 - 1], vec[i1 - 1][i2], vec[i1][i2 - 1]) + 1; }
					}
				}
			}
			return vec[wS1][wS2];
		}
	}
};