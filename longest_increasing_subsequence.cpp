#include <vector>
#include <iostream>

using namespace std;

class LongestIncreasingSubsequence {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> state(nums.size(), 1);
        int result = 1;
//        print(0, 0, nums);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] < nums[j] && state[j] <= state[i]) {
                    state[j] = state[i] + 1;
                }
//                print(i, j, state);
            }
        }
        for (int i : state) {
            if (i > result) {
                result = i;
            }
        }
        return result;
    }

private:
    void print(int i, int j, vector<int>& state) {
        cout << "(" << i << "," << j << ") ";
        for (int i : state) {
            cout << i << " ";
        }
        cout << endl;
    }
};