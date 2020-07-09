#include <vector>

using namespace std;

class SortColors {
public:
    void sortColors(vector<int>& nums) {
        vector<int> first_pos(3, -1);
        vector<int> last_pos(3, -1);

        int i {0};
        while (i < nums.size()) {
            if (nums[i] == 0 && first_pos[1] != -1) {
                swap(nums[i], nums[first_pos[1]]);
                last_pos[0] = first_pos[1];
                first_pos[1]++;
                if (first_pos[0] == -1) {
                    first_pos[0] = last_pos[0];
                }
            } else if (nums[i] == 0 && first_pos[2] != -1) {
                swap(nums[i], nums[first_pos[2]]);
                last_pos[0] = first_pos[1];
                first_pos[2]++;
                if (first_pos[0] == -1) {
                    first_pos[0] = last_pos[0];
                }
            } else if (nums[i] == 1 && first_pos[2] != -1) {
                swap(nums[i], nums[first_pos[2]]);
                last_pos[1] = first_pos[2];
                first_pos[2]++;
                if (first_pos[1] == -1) {
                    first_pos[1] = last_pos[1];
                }
            } else {
                last_pos[nums[i]] = i;
                if (first_pos[nums[i]] == -1) {
                    first_pos[nums[i]] = last_pos[nums[i]];
                }
                i++;
            }
        }
    }
};