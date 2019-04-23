//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
//Note that you cannot sell a stock before you buy one.
//
//Example 1:
//
//Input: [7,1,5,3,6,4]
//Output: 5
//Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//             Not 7-1 = 6, as selling price needs to be larger than buying price.
//
//Example 2:
//
//Input: [7,6,4,3,1]
//Output: 0
//Explanation: In this case, no transaction is done, i.e. max profit = 0.
//

//Runtime: 16 ms, faster than 21.72% of C++ online submissions for Best Time to Buy and Sell Stock.
//Memory Usage : 9.3 MB, less than 98.03% of C++ online submissions for Best Time to Buy and Sell Stock.

// Faster
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) { return 0; }
		int iLow = INT_MAX;
		int rtn = 0;
		for (int i = 0;i < prices.size();++i) {
			if (prices[i] > iLow && (prices[i] - iLow > rtn)) {
				rtn = prices[i] - iLow;
			}
			else if (prices[i] < iLow) {
				iLow = prices[i];
			}
		}
		return rtn;
	}
};

//Runtime: 1152 ms, faster than 5.05% of C++ online submissions for Best Time to Buy and Sell Stock.
//Memory Usage : 9.5 MB, less than 65.73% of C++ online submissions for Best Time to Buy and Sell Stock.

// Looks pretty slow
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) { return 0; }
		for (vector<int>::iterator it = prices.begin(); it != prices.end();++it) {
			vector<int>::iterator itMax = max_element(it, prices.end());
			if (it == itMax) { *it = 0; }
			else { *it = *itMax - *it; }
		}
		return *max_element(prices.begin(), prices.end());
	}
};