#include <vector>

using namespace std;

class ClimbingStairs {
public:
    int climbStairs(int n) {
        int prev1 = 1;
        int prev2 = 1;
        int tmp;
        for (int i = 2; i <= n; i++) {
            tmp = prev1 + prev2;
            prev1 = prev2;
            prev2 = tmp;
        }
        return prev2;
    }
};