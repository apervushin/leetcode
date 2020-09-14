#include <vector>
#include <algorithm>

using namespace std;

class CourseScheduleII {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;

        vector<vector<int>> edges(numCourses);
        for (vector<int>& p : prerequisites) {
            edges[p[0]].push_back(p[1]);
        }

        vector<Status> nodes(numCourses, Status::UNVISITED);

        for (int i = 0; i < edges.size(); i++) {
            if(findCicle(i, edges, nodes, result)) {
                return {};
            }
        }

        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == Status::UNVISITED) {
                result.push_back(i);
            }
        }

        return result;
    }

private:
    enum class Status {
        VISITED,
        VISITING,
        UNVISITED
    };

    bool findCicle(int node, vector<vector<int>>& edges, vector<Status>& nodes, vector<int>& path) {
        if (nodes[node] == Status::VISITED) {
            return false;
        }
        if (nodes[node] == Status::VISITING) {
            return true;
        }
        nodes[node] = Status::VISITING;
        for (int i = 0; i < edges[node].size(); i++) {
            if (findCicle(edges[node][i], edges, nodes, path)) {
                return true;
            }
        }
        path.push_back(node);
        nodes[node] = Status::VISITED;
        return false;
    }
};