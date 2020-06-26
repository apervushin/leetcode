#include <vector>
#include <unordered_map>
using namespace std;

class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (auto i = 0; i < nums.size(); i++) {
            auto got = m.find(target - nums[i]);
            if (got != m.end()) {
                return {got->second, i};
            }
            m[nums[i]] = i;
        }
        return {};
    }

};