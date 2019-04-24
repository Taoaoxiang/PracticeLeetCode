//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete at most k transactions.
//
//Note:
//You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//
//Example 1:
//
//Input: [2,4,1], k = 2
//Output: 2
//Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
//
//Example 2:
//
//Input: [3,2,6,5,0,3], k = 2
//Output: 7
//Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
//             Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//

//Runtime: 8 ms, faster than 99.43% of C++ online submissions for Best Time to Buy and Sell Stock IV.
//Memory Usage : 8.8 MB, less than 97.20% of C++ online submissions for Best Time to Buyand Sell Stock IV.

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int len = prices.size();
		if (len <= 1 || k == 0) { return 0; }
		// We have to use this easy solution for the unlimited purchase and sell
		// Otherwise it will exceed memory limit
		if (k > len / 2) {
			int rtn = 0;
			for (int i = 0; i < len;++i) {
				if ((i < len - 1) && prices[i + 1] > prices[i]) {
					rtn += (prices[i + 1] - prices[i]);
				}
			}
			return rtn;
		}
		vector<int> qPros(k, 0);
		vector<int> qBuys(k, INT_MIN);
		for (int i = 0;i < len;++i) {
			int price = prices[i];
			int lastPro = 0;
			for (int k1 = 0; k1 < k; ++k1) {
				qBuys[k1] = (lastPro - price) > qBuys[k1] ? (lastPro - price) : qBuys[k1];
				qPros[k1] = (qBuys[k1] + price) > qPros[k1] ? (qBuys[k1] + price) : qPros[k1];
				lastPro = qPros[k1];
			}
		}
		return qPros.back();
	}
};