#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class FindTheCityWithTheSmallestNumberOfNeighborsAtAThresholdDistance {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long>> distances(n, vector<long>(n, INT_MAX));

        for (vector<int>& e : edges) {
            distances[e[0]][e[1]] = e[2];
            distances[e[1]][e[0]] = e[2];
        }
        for (int i = 0; i < n; i++) {
            distances[i][i] = 0;
        }

        //print(distances);

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }

        //print(distances);

        int best = INT_MAX;
        int best_i = 0;
        for (int i = 0; i < n; i++) {
            int tmp = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && distances[i][j] <= distanceThreshold) {
                    tmp++;
                }
            }

            if (tmp <= best) {
                best_i = i;
                best = tmp;
            }
        }

        return best_i;
    }

private:
    void print(const vector<vector<long>>& distances) {
        for (const auto & distance : distances) {
            for (long j : distance) {
                cout << j << " ";
            }
            cout << "\n";
        }
        cout << endl;
    }
};