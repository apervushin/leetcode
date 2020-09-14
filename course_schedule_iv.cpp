#include <vector>

using namespace std;

class CourseScheduleIV {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> result(queries.size());
        vector<int> nodes(n, -1);
        vector<vector<int>> edges(n);

        for (vector<int>& p : prerequisites) {
            edges[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < queries.size(); i++) {
            result[i] = isReachable(i, queries[i][0], queries[i][1], nodes, edges);
        }

        return result;
    }

private:
    bool isReachable(int query_id, int from_node, int to_node, vector<int>& nodes, vector<vector<int>>& edges) {
        if (from_node == to_node) {
            return true;
        }
        if (nodes[from_node] == query_id) {
            return false;
        }
        nodes[from_node] = query_id;
        for (auto& e : edges[from_node]) {
            if(isReachable(query_id, e, to_node, nodes, edges)) {
                return true;
            }
        }

        return false;
    }
};