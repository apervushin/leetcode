#include <vector>
#include <iostream>

class Solution {
public:
    int countPrimes(int n) {
        int result = 0;
        std::vector<bool> numbers(n, true);
        for (int i = 2; i < n; ++i) {
            if (numbers[i]) {
                ++result;
                for (int j = i; j <= n; j += i) {
                    numbers[j] = false;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    std::cout << s.countPrimes(10) << '\n';
}