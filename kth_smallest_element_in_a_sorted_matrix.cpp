#include <vector>
#include <algorithm>

using namespace std;

class KthSmallestElementInASortedMatrix {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int min = matrix[0][0];
        int max = matrix[n - 1][n - 1];
        int result = 0;

        while (min <= max) {
            int mid = min + ((max - min) / 2);
            int greaterCnt = countGreaterElements(matrix, mid);

            if (greaterCnt < k) {
                min = mid + 1;
            } else {
                result = mid;
                max = mid - 1;
            }
        }

        return result;
    }

private:
    int countGreaterElements(vector<vector<int>>& matrix, int a) {
        int result = 0;
        for (int i = 0; i < matrix.size(); i++) {
            auto find = upper_bound(matrix[i].begin(), matrix[i].end(), a);
            result += find - matrix[i].begin();
        }
        return result;
    }
};