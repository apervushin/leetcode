#include <vector>
#include <iostream>

using namespace std;

class Subsets {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.push_back({});
        for (int i = 1; i <= nums.size(); i++) {
            vector<int> v;
            subsets(nums, i, 0, v);
        }
        return result;
    }

private:
    vector<vector<int>> result;

    void subsets(vector<int>& nums, int size, int startPos, vector<int>& current_result) {
        if (size == 0) {
            result.push_back(current_result);
            return;
        }
        for (int i = startPos; i + size <= nums.size(); i++) {
            current_result.push_back(nums[i]);
            subsets(nums, size - 1, i + 1, current_result);
            current_result.pop_back();
        }
    }
};