#include <vector>
#include <iostream>

using namespace std;

class MergeSortedArray {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        --m;
        --n;
        int pos = nums1.size() - 1;
        while (pos >= 0) {
            if (m < 0 || (n >= 0 && nums2[n] >= nums1[m])) {
                nums1[pos] = nums2[n--];
            } else if (n < 0 || (m >= 0 && nums1[m] >= nums2[n])) {
                nums1[pos] = nums1[m--];
            }
            --pos;
        }
    }
};