#include <string>
#include <unordered_map>

using namespace std;

class RomanToInteger {
public:
    int romanToInt(string s) {
        int result {0};
        int pos {0};
        while (pos < s.length()) {
            if (pos < s.length() - 1 && values[s[pos]] < values[s[pos + 1]]) {
                result += (values[s[pos + 1]] - values[s[pos]]);
                pos += 2;
            } else {
                result += values[s[pos]];
                ++pos;
            }
        }
        return result;
    }

private:
    unordered_map<char, int> values = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'I', 1},
            {'D', 500},
            {'M', 1000},
    };
};