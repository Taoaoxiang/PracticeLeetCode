#include "include_LeetCode.h"


class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int len = prices.size();
		if (len <= 1 || k == 0) { return 0; }
		if (k > len / 2) {
			int rtn = 0;
			for (int i = 0; i < len;++i) {
				if ((i < len - 1) && prices[i+1]>prices[i]) {
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





int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}