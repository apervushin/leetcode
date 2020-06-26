#include <vector>
#include <climits>

using namespace std;

class FindFirstandLastPositionofElementinSortedArray {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        search(nums, target, 0, nums.size() - 1, SearchType::ANY);
        return {
            min_pos == INT_MAX ? -1 : min_pos,
            max_pos == INT_MIN ? -1 : max_pos
        };
    }

private:
    int min_pos {INT_MAX};
    int max_pos {INT_MIN};

    enum class SearchType {
        MIN,
        MAX,
        ANY
    };

    void search(vector<int>& nums, int target, int start_pos, int end_pos, SearchType type) {
        if(start_pos > end_pos) {
            return;
        }
        int mid_pos {start_pos + ((end_pos - start_pos) / 2)};

        if (nums[mid_pos] > target) {
            search(nums, target, 0, mid_pos - 1, type);
        } else if (nums[mid_pos] < target) {
            search(nums, target, mid_pos + 1, end_pos, type);
        } else {
            min_pos = min(min_pos, mid_pos);
            max_pos = max(max_pos, mid_pos);
            if (type != SearchType::MAX) {
                search(nums, target, 0, mid_pos - 1, SearchType::MIN);
            }
            if (type != SearchType::MIN) {
                search(nums, target, mid_pos + 1, end_pos, SearchType::MAX);
            }
        }
    }
};