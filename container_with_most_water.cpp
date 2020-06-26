#include <vector>

using namespace std;

class ContainerWithMostWater {
public:
    int maxArea(vector<int>& height) {
        size_t i {0};
        size_t j {height.size() - 1};
        int result {0};

        while (i < j) {
            int s = min(height[i], height[j]) * (j - i);
            if (result < s) {
                result = s;
            }
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return result;
    }
};