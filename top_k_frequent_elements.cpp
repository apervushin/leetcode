#include <vector>
#include <map>
#include <queue>

using namespace std;

class TopKFrequentElements {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> state;
        priority_queue<pair<int, int>> counts;
        vector<int> result;
        for (int v : nums) {
            auto f = state.find(v);
            if (f == state.end()) {
                state.insert(pair<int, int>(v, 1));
            } else {
                f->second++;
            }
        }
        for (auto v : state) {
            counts.push(pair<int, int>(v.second, v.first));
        }
        for (int i {0}; i < k; i++) {
            result.push_back(counts.top().second);
            counts.pop();
        }
        return result;
    }
};