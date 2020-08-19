#include <iostream>
#include "spiral_matrix.cpp"
#include <climits>

using namespace std;

int main() {
    SpiralMatrix s;

    vector<vector<int>> input = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
//    vector<vector<int>> input = {
//            {1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12}
//    };
//    vector<vector<int>> input = {
//            {1, 2, 3, 4}
//    };
//    vector<vector<int>> input = {
//            {1},
//            {2}
//    };
    vector<int> result = s.spiralOrder(input);

    for (int r : result) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
