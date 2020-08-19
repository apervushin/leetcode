#include <vector>

using namespace std;

class SpiralMatrix {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int height_padding {0};
        int width_padding {0};
        int height = matrix.size();
        if (height == 0) {
            return result;
        }
        int width = matrix[0].size();
        if (width == 0) {
            return result;
        }
        while (check(width_padding, width) && check(height_padding, height)) {
            for (int i = width_padding; i < width - width_padding; ++i) {
                result.push_back(matrix[height_padding][i]);
            }
            for (int i = height_padding + 1; i < height - height_padding; ++i) {
                result.push_back(matrix[i][width - width_padding - 1]);
            }
            if (height_padding != height - height_padding - 1) {
                for (int i = width - width_padding - 2; i >= width_padding; --i) {
                    result.push_back(matrix[height - height_padding - 1][i]);
                }
            }
            if (width - width_padding - 1 != width_padding) {
                for (int i = height - height_padding - 2; i >= height_padding + 1; --i) {
                    result.push_back(matrix[i][width_padding]);
                }
            }
            ++width_padding;
            ++height_padding;
        }

        return result;
    }

private:
    bool check(int padding, int size) {
        return size % 2 == 0 ? padding < size / 2 : padding <= size / 2;
    }
};