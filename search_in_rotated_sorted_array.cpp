#include <vector>

using namespace std;

class SearchInRotatedSortedArray {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) {
            return -1;
        }
        int pivot_position = findPivotPosition(nums);
        if (pivot_position == -1) {
            return search(nums, target, 0, nums.size() - 1);
        } else if (nums[0] > target) {
            return search(nums, target, pivot_position, nums.size() - 1);
        }
        return search(nums, target, 0, pivot_position - 1);
    }

private:
    int findPivotPosition(vector<int>& nums) {
        return findPivotPosition(nums, 0, nums.size() - 1);
    }

    int findPivotPosition(vector<int>& nums, int start_pos, int end_pos) {
        if (start_pos == end_pos) {
            return nums[start_pos] < nums[0] ? start_pos : -1;
        }

        int middle_pos = start_pos + ((end_pos - start_pos) / 2);

        if (nums[middle_pos] < nums[0]) {
            return findPivotPosition(nums, start_pos, middle_pos);
        }

        return findPivotPosition(nums, middle_pos + 1, end_pos);
    }

    int search(vector<int>& nums, int target, int start_pos, int end_pos) {
        if (end_pos < start_pos) {
            return -1;
        }
        int middle_pos = start_pos + ((end_pos - start_pos) / 2);
        if(nums[middle_pos] > target) {
            return search(nums, target, start_pos, middle_pos - 1);
        } else if(nums[middle_pos] < target) {
            return search(nums, target, middle_pos + 1, end_pos);
        }
        return middle_pos;
    }
};