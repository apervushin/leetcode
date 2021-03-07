#include <vector>
#include <queue>

using namespace std;

class ReorderRoutestoMakeAllPathsLeadtotheCityZero {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> nodes(n);
        vector<vector<pair<int, bool>>> edges(n);
        queue<int> queue;
        int result = 0;

        for (vector<int>& c : connections) {
            edges[c[0]].push_back({c[1], false});
            edges[c[1]].push_back({c[0], true});
        }

        queue.push(0);
        while (!queue.empty()) {
            int node = queue.front();
            nodes[node] = true;
            queue.pop();
            for (auto& e : edges[node]) {
                if (!nodes[e.first]) {
                    queue.push(e.first);
                    if (!e.second) {
                        result++;
                    }
                }
            }
        }

        return result;
    }
};