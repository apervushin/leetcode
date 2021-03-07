#include <cstdint>
#include <iostream>
#include <bitset>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;

        //std::cout << std::bitset<32>(n) << ' ' << std::bitset<32>(result) << '\n';

        for (int i = 0; i < 32; ++i) {
            result |= n & 1;
            n >>= 1;
            if (i != 31) {
                result <<= 1;
            }
            //std::cout << std::bitset<32>(n) << ' ' << std::bitset<32>(result) << '\n';
        }

        return result;
    }
};

int main() {
    Solution s;
    std::cout << s.reverseBits(4294967293) << '\n';
    return 0;
}