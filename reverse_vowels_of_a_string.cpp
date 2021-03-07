#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        if (s.empty()) {
            return s;
        }
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (isVowel(s[i]) && isVowel(s[j])) {
                swap(s[i], s[j]);
                ++i;
                --j;
            } else {
                if (!isVowel(s[i])) {
                    ++i;
                }
                if (!isVowel(s[j])) {
                    --j;
                }
            }
        }

        return s;
    }

private:
    const std::vector<int> vowels = {true, false, false, false, true, false, false, false, true, false, false, false, false, false, true, false, false, false, false, false, true, false, false, false, false, false};

    bool isVowel(char c) {
        return isalpha(c) && ((islower(c) && vowels[c - 'a']) || (isupper(c) && vowels[c - 'A']));
    }
};

int main() {
    Solution s;
    std::cout << s.reverseVowels("leetcode") << '\n';
    return 0;
}