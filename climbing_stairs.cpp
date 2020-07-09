#include <vector>

using namespace std;

class ClimbingStairs {
public:
    int climbStairs(int n) {
        vector<int> state;
        return climbStairs(n, 0, state);
    }

private:
    int climbStairs(int n, int pos, vector<int>& state) {
        if (n == pos) {
            return 0;
        }
        if (n - pos == 1) {
            return 1;
        }
        if (n - pos == 2) {
            return 2;
        }
    }
};