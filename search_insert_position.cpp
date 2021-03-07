#include <vector>
#include <iostream>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.back() < target) {
            return nums.size();
        }
        int start = 0;
        int end = nums.size() - 1;
        while (start != end) {
            int middle = start + ((end - start) / 2);
            if (nums[middle] == target) {
                return middle;
            } else if (nums[middle] > target) {
                end = middle;
            } else {
                start = middle + 1;
            }
        }
        return start + ((end - start) / 2);
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> inputs = {{}, {1,2,3,4}, {1,2,3,4}, {1,2,3,4}, {1,3}, {1,3,5,6}, {1,3,5,6}};
    std::vector<int> targets = {1, 1, 4, 3, 2, 2, 7};
    std::vector<int> answers = {0, 0, 3, 2, 1, 1, 4};

    for (int i = 0; i < inputs.size(); ++i) {
        std::cout << s.searchInsert(inputs[i], targets[i]) << ' ' << answers[i] << '\n';
    }

    return 0;
}