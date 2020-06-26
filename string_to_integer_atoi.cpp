#include <string>
#include <bits/stdc++.h>

using namespace std;

class StringToInteger {
public:
    int myAtoi(string str) {
        int firstNumericPos {-1};
        int lastNumericPos {-1};
        int minusPos {-1};
        int plusPos {-1};
        for (int i {0}; i < str.length(); i++) {
            char c {str[i]};
            if (firstNumericPos == -1) {
                if (c == ' ') {
                    if(minusPos != -1 || plusPos != -1) {
                        return 0;
                    }
                } else if (c == '-') {
                    if(minusPos != -1 || plusPos != -1) {
                        return 0;
                    }
                    minusPos = i;
                } else if (c == '+') {
                    if(minusPos != -1 || plusPos != -1) {
                        return 0;
                    }
                    plusPos = i;
                } else if (c < '0' || c > '9') {
                    return 0;
                } else {
                    firstNumericPos = i;
                }
            } else if (c < '0' || c > '9') {
                lastNumericPos = i - 1;
                break;
            }
        }

        if (lastNumericPos == -1) {
            lastNumericPos = str.length() - 1;
        }

        if (firstNumericPos == -1) {
            return 0;
        }

        int result = 0;
        while (lastNumericPos >= firstNumericPos) {
            int p = ((int)str[firstNumericPos] - 48) * (minusPos == -1 ? 1 : -1);
            if (isOverflow(result, p, minusPos != -1)) {
                return minusPos == -1 ? INT_MAX : INT_MIN;
            }
            result = result * 10 + p;
            firstNumericPos++;
        }

        return result;
    }

private:
    static bool isOverflow(int result, int p, bool minus) {
        if (!minus && INT_MAX / 10 < result) {
            return true;
        }
        if (!minus && INT_MAX - result * 10 < p) {
            return true;
        }
        if (minus && INT_MIN / 10 > result) {
            return true;
        }
        if (minus && INT_MIN - result * 10 > p) {
            return true;
        }
        return false;
    }
};