#include <vector>

using namespace std;

class CriticalConnectionsinaNetwork {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> result;
        vector<int> nodes(n, -1);
        vector<vector<int>> edges(n);
        vector<int> up(n);
        int counter = 0;

        for (vector<int>& conn : connections) {
            edges[conn[0]].push_back(conn[1]);
            edges[conn[1]].push_back(conn[0]);
        }
        for (int i = 0; i < n; i++) {
            if (nodes[i] == -1) {
                criticalConnections(i, -1, counter, nodes, edges, up, result);
            }
        }

        return result;
    }

private:
    void criticalConnections(int node, int parent_node, int& counter,
                             vector<int>& nodes, const vector<vector<int>>& edges,
                             vector<int>& up, vector<vector<int>>& result) {
        nodes[node] = up[node] = counter++;
        for (int child_node : edges[node]) {
            if (child_node == parent_node) {
                continue;
            } else if (nodes[child_node] != -1) {
                up[node] = min(up[node], nodes[child_node]);
            } else {
                criticalConnections(child_node, node, counter, nodes, edges, up, result);
                up[node] = min(up[node], up[child_node]);
                if (up[child_node] > nodes[node]) {
                    result.push_back({node, child_node});
                }
            }
        }
    }
};
