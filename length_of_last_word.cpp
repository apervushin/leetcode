#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int i = s.length();
        while (i > 0 && s[i - 1] == ' ') {
            --i;
        }
        int j = i;
        while (j > 0 && s[j - 1] != ' ') {
            --j;
        }
        return i - j;
    }
};