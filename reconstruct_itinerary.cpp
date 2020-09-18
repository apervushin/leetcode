#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;

class ReconstructItinerary {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, map<string, int>> edges;
        vector<string> result;
        const string start_node = "JFK";
        int edges_cnt = 0;

        for (auto& t : tickets) {
            auto find = edges.find(t[0]);
            if (find == edges.end()) {
                edges.insert({t[0], {{t[1], 1}}});
            } else {
                auto find2 = find->second.find(t[1]);
                if (find2 == find->second.end()) {
                    find->second.insert({t[1], 1});
                } else {
                    find2->second++;
                }
            }
            edges_cnt++;
        }

        dfs(start_node, edges, result, edges_cnt);

        return result;
    }

private:
    bool dfs(const string& node, unordered_map<string, map<string, int>>& edges, vector<string>& result, int edged_left) {
        result.push_back(node);
//        for(auto b : result) {
//            cout << b << " ";
//        }
//        cout << endl;
        if (edged_left == 0) {
            return true;
        }
        auto find = edges.find(node);
        if (find == edges.end()) {
            result.pop_back();
            return false;
        }
        for (auto& find2 : find->second) {
//            cout << "{\"" << node << "\",\"" << find2.first << "\"} " << find2.second << endl;
            if (find2.second == 0) {
                continue;
            }
            find2.second--;
            if (dfs(find2.first, edges, result, edged_left - 1)) {
                return true;
            }
            find2.second++;
        }
        result.pop_back();
        return false;
    }
};
