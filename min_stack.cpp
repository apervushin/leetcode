#include <stack>

using namespace std;

class MinStack {
public:
    MinStack() {

    }

    void push(int x) {
        values.push(x);
        if (!minValues.empty()) {
            minValues.push(min(minValues.top(), x));
        } else {
            minValues.push(x);
        }
    }

    void pop() {
        values.pop();
        minValues.pop();
    }

    int top() {
        return values.top();
    }

    int getMin() {
        return minValues.top();
    }

private:
    stack<int> values;
    stack<int> minValues;
};