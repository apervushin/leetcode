#include <vector>

using namespace std;

class UniqueBinarySearchTrees {
public:
    int numTrees(int n) {
        vector<int> state(max(n + 1, 3), -1);
        state[0] = 1;
        state[1] = 1;
        state[2] = 2;
        return numTrees(state, n);
    }

private:
    int numTrees(vector<int>& state, int n) {
        if (state[n] != -1) {
            return state[n];
        }
        int result = 0;
        for (int i = 1; i <= n; i++) {
            result += numTrees(state, i - 1) * numTrees(state,n - i);
        }
        state[n] = result;
        return result;
    }
};