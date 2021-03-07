#include <vector>
#include <iostream>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int size = nums.size();
        int first_free_pos = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) {
                --size;
                if (first_free_pos == -1) {
                    first_free_pos = i;
                }
            } else if (first_free_pos != -1) {
                std::swap(nums[i], nums[first_free_pos]);
                ++first_free_pos;
            }
        }

        return size;
    }
};

int main() {
    Solution s;

    std::vector<int> input = {3,2,2,3};

    int result = s.removeElement(input, 3);
    for (int i = 0; i < result; ++i) {
        std::cout << input[i] << ' ';
    }

    return 0;
}