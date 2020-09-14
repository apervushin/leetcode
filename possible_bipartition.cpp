#include <vector>
#include <queue>

using namespace std;

class PossibleBipartition {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> nodes(N);
        vector<vector<int>> edges(N);
        queue<int> queue;

        for (vector<int>& d : dislikes) {
            edges[d[0] - 1].push_back(d[1] - 1);
            edges[d[1] - 1].push_back(d[0] - 1);
        }

        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] != 0) {
                continue;
            }
            nodes[i] = 1;
            queue.push(i);
            while (!queue.empty()) {
                int node = queue.front();
                queue.pop();
                int group = nodes[node];

                for (int e : edges[node]) {
                    if (nodes[e] == 0) {
                        nodes[e] = group == 1 ? 2 : 1;
                        queue.push(e);
                    } else if (nodes[e] == group) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
