#include <vector>

using namespace std;

class BestTimeToBuyAndSellStock {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int min_val = prices[0];
        int result = 0;
        for (int i = 0; i < prices.size(); i++) {
            result = max(result, prices[i] - min_val);
            min_val = min(min_val, prices[i]);
        }
        return result;
    }
};