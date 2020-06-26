#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class LetterCombinationsOfAPhoneNumber {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        letterCombinations(digits, "");
        return result;
    }

private:
    void letterCombinations(string digits, string prefix) {
        if (digits.empty()) {
            result.push_back(prefix);
            return;
        }
        string chars = keyboard[digits[0]];
        for (int i = 0; i < chars.length(); i++) {
            string s = prefix;
            letterCombinations(digits.substr(1), s.append(chars.substr(i, 1)));
        }
    }

    vector<string> result;

    unordered_map<char, const string> keyboard = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
    };
};