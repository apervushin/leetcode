#include <vector>
#include <algorithm>

using namespace std;

class MergeIntervals {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            if (!result.empty() && result[result.size() - 1][1] >= intervals[i][0]) {
                result[result.size() - 1][1] = max(intervals[i][1], result[result.size() - 1][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};