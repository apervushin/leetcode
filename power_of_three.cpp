#include <iostream>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1) {
            return true;
        }
        long i = 3;
        while (i < n) {
            i *= 3;
        }
        return i == n;
    }
};

int main() {
    Solution s;

    std::cout << s.isPowerOfThree(27) << '\n';

    return 0;
}