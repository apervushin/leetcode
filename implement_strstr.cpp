#include <string>
#include <iostream>

using namespace std;

class ImplementStrStr {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        if (haystack.empty() || needle.length() > haystack.length()) {
            return -1;
        }

        int result {-1};

        for (int i {0}; i < haystack.length() - needle.length() + 1; i++) {
            if (haystack[i] == needle[0]) {
                bool equals = true;
                for (int j = 1; j < needle.length(); j++) {
                    if (haystack[i + j] != needle[j]) {
                        equals = false;
                        break;
                    }
                }
                if(equals) {
                    return i;
                }
            }
        }

        return result;
    }
};