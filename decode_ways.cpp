#include <string>

using namespace std;

class DecodeWays {
public:
    int numDecodings(string s) {
        int state[s.size() + 1];
        state[s.size()] = 1;
        if (s[s.size() - 1] == '0') {
            state[s.size() - 1] = 0;
        } else {
            state[s.size() - 1] = 1;
        }
        for (int i = s.size() - 2; i >= 0 ; --i) {
            if (s[i] == '0') {
                state[i] = 0;
            } else if (i < s.length() - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                state[i] = state[i + 2] + state[i + 1];
            } else {
                state[i] = state[i + 1];
            }
        }
        return state[0];
    }
};