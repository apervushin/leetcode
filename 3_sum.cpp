#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class ThreeSum {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        sort(nums.begin(), nums.end());

        int i = 0;
        while (i < nums.size()) {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (j < k && nums[j - 1] == nums[j]) {
                        j++;
                    }
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else {
                    j++;
                }
            }
            i++;
            while (i < nums.size() && nums[i - 1] == nums[i]) {
                i++;
            }
        }
        return result;
    }
};