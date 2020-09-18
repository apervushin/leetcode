#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class MinimumWindowSubstring {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_state; // number on t's characters in current window
        unordered_map<char, int> s_state; // number on s's characters in current window

        int required_chars_cnt = 0;
        int actual_chars_cnt = 0;

        int result_start_pos = 0;
        int result_end_pos = INT_MAX;

        for (char c : t) {
            auto find = t_state.find(c);
            if (find == t_state.end()) {
                t_state.insert({c, 1});
            } else {
                find->second++;
            }
        }
        required_chars_cnt = t_state.size();

        int i = 0, j = 0;
        while (j < s.length()) {
            char c = s[j];

            auto find = s_state.find(c);
            if (find == s_state.end()) {
                s_state.insert({c, 1});
            } else {
                find->second++;
            }

            find = t_state.find(c);
            if (find != t_state.end() && find->second == s_state[c]) {
                actual_chars_cnt++;
            }

            while (actual_chars_cnt == required_chars_cnt) {
                if (result_end_pos - result_start_pos > j - i) {
                    result_end_pos = j;
                    result_start_pos = i;
                }

                char c_delete = s[i];
                s_state[c_delete]--;
                find = t_state.find(c_delete);
                if (find == t_state.end()) {
                    i++;
                    continue;
                }
                if (find->second > s_state[c_delete]) {
                    actual_chars_cnt--;
                }
                i++;
            }

            j++;
        }

        return result_end_pos == INT_MAX ? "" : s.substr(result_start_pos, result_end_pos - result_start_pos + 1);
    }
};