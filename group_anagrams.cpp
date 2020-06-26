#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class GroupAnagrams {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> state;
        vector<vector<string>> result;

        for (auto & str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            auto iterator = state.find(s);
            if (iterator == state.end()) {
                vector<string> v= {str};
                state[s] = v;
            } else {
                iterator->second.push_back(str);
            }
        }

        for (auto iterator = state.begin(); iterator != state.end(); iterator++) {
            result.push_back(iterator->second);
        }

        return result;
    }
};