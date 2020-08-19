#include <iostream>
#include <bitset>
#include <climits>

using namespace std;

class DivideTwoIntegers {
public:
    int divide(long dividend, long divisor) {
        int sign = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) ? -1 : 1;

        dividend = abs(dividend);
        divisor = abs(divisor);

        cout << print(dividend) << endl;
        cout << print(divisor) << endl;

        long result = 0;
        long tmp = 0;

        for (int i = 31; i>= 0; i--) {
            if (tmp + (divisor << i) <= dividend) {
                tmp += divisor << i;
                result |= 1L << i;
            }

            cout << i << endl << print(tmp) << endl << print(result) << endl << endl;
        }

        result = sign * result;

        return result > INT_MAX ? INT_MAX : result < INT_MIN ? INT_MIN : result;
    }

    int add(int a, int b) {
        while (b != 0) {
            int carry = a & b;
            a = a ^ b;
            b = (carry << 1);
        }
        return a;
    }

    int substract(int a, int b) {
        while (b != 0) {
            int carry = (~a) & b;
            a = a ^ b;
            b = (carry << 1);
        }
        return a;
    }

    int multiply(int a, int b) {
        bool negative = (a < 0 && b > 0) || (a > 0 && b < 0);
        a = abs(a);
        b = abs(b);
        int result {0};
        while (b != 0) {
            if (b & 1) {
                result += a;
            }
            a <<= 1;
            b >>= 1;
        }
        if (negative) {
            result = makeNegative(result);
        }
        return result;
    }

    string print(int a) {
        return bitset<64>(a).to_string();
    }

    int makeNegative(int a) {
        int n {1};
        a = ~a;
        while (a & n) {
            a = a & (~n);
            n <<= 1;
            cout << endl;
        }
        return a | n;
    }
};