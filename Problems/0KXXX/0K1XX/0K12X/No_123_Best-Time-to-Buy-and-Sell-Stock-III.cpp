//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit. You may complete at most two transactions.
//
//Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
//
//Example 1:
//
//Input: [3,3,5,0,0,3,1,4]
//Output: 6
//Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
//
//Example 2:
//
//Input: [1,2,3,4,5]
//Output: 4
//Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
//             engaging multiple transactions at the same time. You must sell before buying again.
//
//Example 3:
//
//Input: [7,6,4,3,1]
//Output: 0
//Explanation: In this case, no transaction is done, i.e. max profit = 0.
//
//
//Runtime: 8 ms, faster than 99.25% of C++ online submissions for Best Time to Buy and Sell Stock III.
//Memory Usage : 9.5 MB, less than 69.35% of C++ online submissions for Best Time to Buyand Sell Stock III.

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int pro1 = 0, pro2 = 0;
		int buy1 = INT_MIN, buy2 = INT_MIN;
		for (int i = 0;i < prices.size();++i) {
			buy1 = (-prices[i]) > buy1 ? (-prices[i]) : buy1;
			pro1 = (buy1 + prices[i]) > pro1 ? (buy1 + prices[i]) : pro1;
			buy2 = (pro1 - prices[i]) > buy2 ? (pro1 - prices[i]) : buy2;
			pro2 = (buy2 + prices[i]) > pro2 ? (buy2 + prices[i]) : pro2;
			//cout << "i=>" << i << ", b1=>" << buy1 << ", p1=>" << pro1 << ", b2=>" << buy2 << ", pro2=>" << pro2 << endl;
		}
		return pro2;
	}
};
