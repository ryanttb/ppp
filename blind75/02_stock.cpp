class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			vector<int> profits;
			profits.reserve(prices.size());
	
			int maxProfit{0};
	
			// can't sell until 2nd day
			profits[0] = 0;
			for (size_t sellPriceIdx{1}; sellPriceIdx < prices.size(); ++sellPriceIdx) {
				int price = prices[sellPriceIdx];
				profits[sellPriceIdx] = 0;
	
				for (size_t buyPriceIdx{0}; buyPriceIdx < sellPriceIdx; ++buyPriceIdx) {                
					int profit = price - prices[buyPriceIdx];
					cout << "buy: " << buyPriceIdx << "," << prices[buyPriceIdx] << ", sell: " << sellPriceIdx << "," << prices[sellPriceIdx] << ", profit: " << profit << endl;
	
					profits[sellPriceIdx] = max(profits[sellPriceIdx], profit);
					maxProfit = max(maxProfit, profits[sellPriceIdx]);
				}
			}
			return maxProfit;
		}

		int maxProfitOnePass(vector<int>& prices) {
			int buyPrice = prices[0];
			int profit = 0;

			// can't sell on first day
			for (int i = 1; i < prices.size(); i++) {
				if (buyPrice > prices[i]) {
					buyPrice = prices[i];
				}
				profit = max(profit, prices[i] - buyPrice);
			}
			return profit;
		}
	};