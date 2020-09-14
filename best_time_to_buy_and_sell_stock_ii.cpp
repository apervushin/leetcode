#include <vector>

using namespace std;

class BestTimeToBuyAndSellStockII {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int buy_pos = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[buy_pos] < prices[i]) {
                result += prices[i] - prices[buy_pos];
            }
            buy_pos = i;
        }
        return result;
    }
};