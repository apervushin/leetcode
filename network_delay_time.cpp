#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

class NetworkDelayTime {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> nodes(N, INT_MAX);
        vector<unordered_map<int, int>> edges(N);
        queue<int> queue;

        for (vector<int>& t : times) {
            edges[t[0] - 1].insert({t[1] - 1, t[2]});
        }

        queue.push(K - 1);
        nodes[K - 1] = 0;
        while (!queue.empty()) {
            auto node = queue.front();
            queue.pop();
            for(auto& e : edges[node]) {
                if (nodes[node] + e.second < nodes[e.first]) {
                    nodes[e.first] = nodes[node] + e.second;
                    queue.push(e.first);
                }
            }
        }

        int result = INT_MIN;
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] > result) {
                result = nodes[i];
            }
            if (nodes[i] == INT_MAX) {
                return -1;
            }
        }
        return result;
    }
};