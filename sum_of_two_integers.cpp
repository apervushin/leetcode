#include "cmath"
#include <iostream>
#include <bitset>

using namespace std;

class SumOfTwoIntegers {
public:
    int getSum(int a, int b) {
        int result = 0;
        int carry = 0;
        for (int i = 0; i < sizeof(int) * 8; i ++) {
            int a1 = (a >> i) & 1;
            int b1 = (b >> i) & 1;
            int sum = a1 ^ b1 ^ carry;
            result |= sum << i;
            carry = (a1 && b1) || ((a1 ^ b1) && carry);
        }

        return result;
    }

private:
    string toBinaryString(int a) {
        return bitset<sizeof(int)*8>(a).to_string();
    }
};