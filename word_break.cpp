#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class WordBreak {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        vector<bool> state (s.length() + 1, false);
        state[0] = true;

        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                string substr = s.substr(j, i - j);
                if (state[j] && wordDictSet.find(substr) != wordDictSet.end()) {
                    state[i] = true;
                    break;
                }
            }
        }

        return state[s.length()];
    }
};