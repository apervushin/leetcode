#include <bits/stdc++.h>
using namespace std;

class ReverseInteger {
public:
    int reverse(int x) {
        int result {0};
        while (x != 0) {
            int p = x % 10;
            x /= 10;
            if (isOverflow(result, p)) {
                return 0;
            }
            result = result * 10 + p;
        }
        return result;
    }

private:
    static bool isOverflow(int result, int p) {
        if (result == 0) {
            return false;
        } else if (result > 0) {
            if (INT_MAX / 10 < result) {
                return true;
            }
            return INT_MAX - result * 10 < p;
        } else {
            if (INT_MIN / 10 > result) {
                return true;
            }
            return INT_MIN - result * 10 > p;
        }
    }
};