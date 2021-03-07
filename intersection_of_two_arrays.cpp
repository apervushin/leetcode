#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums1_set;
        unordered_set<int> result_set;
        vector<int> result;

        for (int i : nums1) {
            nums1_set.insert(i);
        }

        for (int i : nums2) {
            if (nums1_set.find(i) != nums1_set.end()) {
                result_set.insert(i);
            }
        }

        for (int i : result_set) {
            result.push_back(i);
        }

        return result;
    }
};

int main() {
    vector<int> v1 = {4,9,5};
    vector<int> v2 = {9,4,9,8,4};
    Solution s;
    for (int i : s.intersection(v1, v2)) {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}