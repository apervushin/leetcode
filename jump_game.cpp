#include <vector>

using namespace std;

class JumpGame {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        int max_visited_pos {0};

        for (int i = 0; i < nums.size(); i++) {
            if (i > max_visited_pos) {
                return false;
            }
            if (max_visited_pos < i + nums[i]) {
                max_visited_pos = i + nums[i];
            }
        }

        return max_visited_pos >= nums.size() - 1;
    }
};