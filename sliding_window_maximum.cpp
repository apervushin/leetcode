#include <vector>
#include <deque>

using namespace std;

class SlidingWindowMaximum {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result(nums.size() - k + 1);
        deque<int> deque;
        int result_pos = 0;

        for (int i = 0; i < nums.size(); i++) {
            while (!deque.empty() && deque.front() <= i - k) {
                deque.pop_front();
            }

            while (!deque.empty() && nums[i] > nums[deque.back()]) {
                deque.pop_back();
            }

            deque.push_back(i);

            if (i >= k - 1) {
                result[result_pos++] = nums[deque.front()];
            }
        }

        return result;
    }
};