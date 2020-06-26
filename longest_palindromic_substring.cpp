#include <string>
#include <iostream>

using namespace std;

class LongestPalindromicSubstring {
public:
    string longestPalindrome(string s) {
        cout << s << endl;
        if (s.empty()) {
            return s;
        }
        int maxStartPos {0};
        int maxEndPos {0};
        for (int i {0}; i < s.length() - 1; ++i) {
            // check even lengths
            if (s[i] == s[i + 1]) {
                int j {0};
                // todo: отсекать по максимально возможно достижимому палиндрому
                while (i - j >= 0 && i + 1 + j < s.length() && s[i - j] == s[i + 1 + j]) {
                    ++j;
                }
                int startPos {i - (j - 1)};
                int endPos {i + 1 + (j - 1)};
                if (maxEndPos - maxStartPos < endPos - startPos) {
                    maxEndPos = endPos;
                    maxStartPos = startPos;
                }
            }

            // check odd lengths
            if (i > 0 && s[i - 1] == s[i + 1]) {
                int j {2};
                while (i - j >= 0 && i + j < s.length() && s[i - j] == s[i + j]) {
                    ++j;
                }
                int startPos {i - j + 1};
                int endPos {i + j - 1};
                if (maxEndPos - maxStartPos < endPos - startPos) {
                    maxEndPos = endPos;
                    maxStartPos = startPos;
                }
            }
        }
        return s.substr(maxStartPos, maxEndPos - maxStartPos + 1);
    }

};