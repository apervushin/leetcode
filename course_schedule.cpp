#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class CourseSchedule {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; ++i) {
            nodes.push_back(Status::UNVISITED);
        }
        for (auto p : prerequisites) {
            auto find = edges.find(p[0]);
            if (find == edges.end()) {
                edges.insert({p[0], {p[1]}});
            } else {
                find->second.push_back(p[1]);
            }
        }
        return !isCycled();
    }

private:
    enum class Status {
        UNVISITED,
        VISITING,
        VISITED
    };
    unordered_map<int, vector<int>> edges;
    vector<Status> nodes;

    bool isCycled() {
        stack<int> visit;

        for (auto e : edges) {
            visit.push(e.first);
        }

        while (!visit.empty()) {
            int n = visit.top();

            nodes[n] = Status::VISITING;

            bool visited = true;
            for (auto nn : edges[n]) {
                switch (nodes[nn]) {
                    case Status::VISITING:
                        return true;
                    case Status::UNVISITED:
                        visited = false;
                        visit.push(nn);
                        break;
                }
            }
            if (visited) {
                nodes[n] = Status::VISITED;
                visit.pop();
            }
        }

        return false;
    }
};