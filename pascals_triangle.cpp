#include <vector>
#include <iostream>

using namespace std;

class PascalsTriangle {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j <= i; ++j) {
                result[i].push_back(calc(i, j));
            }
        }
        return result;
    }

private:
    int calc(int n, int m) {
        int result {1};
        for (int i = 1; i <= m; i++) {
            result *= n--;
            result /= i;
        }
        return result;
    }
};