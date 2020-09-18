#include <vector>
#include <iostream>

using namespace std;

class RedundantConnection {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> nodes(MAX_N, -1);

        for (vector<int>& e : edges) {
            if (!join(e[0], e[1], nodes)) {
                return e;
            }
        }
        return {-1, -1};
    }

private:
    const int MAX_N = 1001;

    int getParent(const int i, vector<int>& nodes) {
        int result = i;
        while (nodes[result] != -1) {
            result = nodes[result];
        }
        if (result != i) {
            nodes[i] = result;
        }
        return result;
    }

    bool join(int i, int j, vector<int>& nodes) {
        i = getParent(i, nodes);
        j = getParent(j, nodes);
        if (j != i) {
            nodes[j] = i;
            return true;
        }
        return false;
    }
};