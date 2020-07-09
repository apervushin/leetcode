#include <vector>
#include <iostream>

using namespace std;

class RotateImage {
public:
    void rotate(vector<vector<int>>& matrix) {
        int tmp;
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n - (2 * i) - 1; j++) {
                tmp = matrix[i][i + j];
                swap(tmp, matrix[i + j][n - i - 1]);
                swap(tmp, matrix[n - i - 1][n - i - j - 1]);
                swap(tmp, matrix[n - i - j - 1][i]);
                swap(tmp, matrix[i][i + j]);
            }

        }
    }
};