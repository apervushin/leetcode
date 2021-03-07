#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int pos = 0;
        int next = 0;
        while (pos < a.length() || pos < b.length()) {
            int a_val = 0, b_val = 0;
            if (pos < a.length()) {
               a_val = a[a.length() - 1 - pos] - '0';
            }
            if (pos < b.length()) {
                b_val = b[b.length() - 1 - pos] - '0';
            }
            int result_val = a_val + b_val + next;
            if (result_val == 0) {
                result.push_back('0');
                next = 0;
            } else if (result_val == 1) {
                result.push_back('1');
                next = 0;
            } else if (result_val == 2) {
                result.push_back('0');
                next = 1;
            } else {
                result.push_back('1');
                next = 1;
            }
            ++pos;
        }
        if (next == 1) {
            result.push_back('1');
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution s;
    std::cout << s.addBinary("11", "1") << '\n';

    return 0;
}