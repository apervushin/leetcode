#include <string>
#include <stack>

using namespace std;

class ValidParentheses {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isOpen(c)) {
                stack.push(c);
            } else {
                if (stack.empty() || getClose(stack.top()) != c) {
                    return false;
                }
                stack.pop();
            }
        }

        return stack.empty();
    }

private:
    static bool isOpen(char c) {
        return c == '(' || c == '{' || c == '[';
    }
    static char getClose(char c) {
        if (c == '(') {
            return ')';
        }
        if (c == '{') {
            return '}';
        }
        return ']';
    }
};