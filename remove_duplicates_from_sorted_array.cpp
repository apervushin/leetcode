#include <vector>

using namespace std;

class RemoveDuplicatesFromSortedArray {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int firstFreePos {-1};
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (prev == nums[i] && firstFreePos == -1) {
                firstFreePos = i;
            } else if (prev != nums[i] && firstFreePos != -1){
                nums[firstFreePos++] = nums[i];
            }
            prev = nums[i];
        }
        if (firstFreePos != -1) {
            nums.erase(nums.begin() + firstFreePos, nums.end());
        }
        return nums.size();
    }
};