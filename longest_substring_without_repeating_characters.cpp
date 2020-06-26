#include <unordered_map>
using namespace std;

class LongestSubstringWithoutRepeatingCharacters {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_occurrences;
        int max_length {0};
        int start_pos {0};
        for (auto i = 0; i < s.length(); i++) {
            auto iterator = last_occurrences.find(s[i]);
            if (iterator != last_occurrences.end()) {
                max_length = max(max_length, i - start_pos);
                int nextStartPos {iterator->second};
                while (start_pos <= nextStartPos) {
                    last_occurrences.erase(s[start_pos]);
                    start_pos++;
                }
            }
            last_occurrences[s[i]] = i;
        }
        return max(max_length, (int)(s.length() - start_pos));
    }
};