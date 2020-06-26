#include <string>
#include <iostream>

using namespace std;

class CountAndSay {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string s {countAndSay(n - 1)};
        int i {0};
        string result {""};
        while (i < s.length()) {
            int j = i;
            while (s[i] == s[j]) {
                j++;
            }
            int cnt {j - i};
            result.append(to_string(cnt)).append(s.substr(i, 1));
            i += cnt;
        }
        return result;
    }
};