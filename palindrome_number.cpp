#include <bits/stdc++.h>

using namespace std;

class PalindromeNumber {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int result {0};
        int tmp {x};
        while (tmp !=0) {
            if(isOverflow(result, tmp % 10)) {
                return false;
            }
            result = result * 10 + (tmp % 10);
            tmp /= 10;
        }
        return result == x;
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