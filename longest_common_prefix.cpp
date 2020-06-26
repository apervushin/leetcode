#include <vector>
#include <string>

using namespace std;

class LongestCommonPrefix {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        int pos {0};
        while (true) {
            char c;
            for (int i = 0; i < strs.size(); i++) {
                if (pos == strs[i].length()) {
                    return strs[i];
                }
                if (i == 0) {
                    c = strs[i][pos];
                } else if(c != strs[i][pos]) {
                    return strs[i].substr(0, pos);
                }
            }
            ++pos;
        }
    }
};