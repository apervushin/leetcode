#include <string>

using namespace std;

class ValidPalindrome {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            char c1 = tolower(s[i]);
            char c2 = tolower(s[j]);
            if ((c1 < 'a' || c1 > 'z') && (c1 < '0' || c1 > '9')) {
                ++i;
            } else if ((c2 < 'a' || c2 > 'z') && (c2 < '0' || c2 > '9')) {
                --j;
            } else if (c1 != c2) {
                return false;
            } else {
                ++i;
                --j;
            }
        }
        return true;
    }
};