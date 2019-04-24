//Implement strStr().
//
//Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
//Example 1:
//
//Input: haystack = "hello", needle = "ll"
//	Output : 2
//
//	Example 2 :
//
//	Input : haystack = "aaaaa", needle = "bba"
//	Output : -1
//
//	Clarification :
//
//	What should we return when needle is an empty string ? This is a great question to ask during an interview.
//
//	For the purpose of this problem, we will return 0 when needle is an empty string.This is consistent to C's strstr() and Java's indexOf().


//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Implement strStr().
//Memory Usage : 9 MB, less than 99.61% of C++ online submissions for Implement strStr().

// I wrote a recursive method, but the submission tells me that memory limit exceeded
class Solution {
public:
	int strStr(string haystack, string needle) {
		int lenT = haystack.length();
		int lenQ = needle.length();
		if (lenT == 0) {
			if (lenQ == 0) { return 0; }
			else { return -1; }
		}
		else {
			if (lenQ == 0) { return 0; }
			else {
				int i = 0;
				while (i < (lenT - lenQ + 1)) {
					int i2 = 0;
					if (haystack[i] == needle[i2]) {
						while (i2 < lenQ) {
							++i2;
							if (i2 >= lenQ) { return i; }
							if (haystack[i + i2] != needle[i2]) { break; }
						}
					}
					++i;
				}
				return -1;
			}
		}
		return -1;
	}
};