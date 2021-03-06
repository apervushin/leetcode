#include <vector>

using namespace std;

class Permutations {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permute(nums, 0, result);
        return move(result);
    }

    void permute(vector<int>& nums, int pos, vector<vector<int>>& result) {
        if (pos == nums.size() - 1) {
            result.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[pos], nums[i]);
            permute(nums, pos + 1, result);
            swap(nums[pos], nums[i]);
        }
    }
};