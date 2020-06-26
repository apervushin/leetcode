#include <vector>

using namespace std;

class FirstMissingPositive {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> stat = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int v : nums) {
            if (v <= 0) {
                continue;
            }

        }
        return -1;
    }
};