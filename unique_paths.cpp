#include <vector>
#include <iostream>

using namespace std;

class UniquePaths {
public:
    int uniquePaths(int m, int n) {
        vector<int> state(m, 1);

        for (int i = 0; i < n - 1; i++) {
            for (int j = 1; j < m; j++) {
                state[j] = state[j] + state[j - 1];
            }
        }
        return state[m - 1];
    }
};