#include <vector>

using namespace std;

class NestedInteger {
public:
    NestedInteger(int valInt) : val_int(valInt), is_integer{true} {}

    NestedInteger(const vector<NestedInteger> &valVector) : val_vector(valVector), is_integer{false} {}

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const {
        return is_integer;
    }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const {
        return val_int;
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const {
        return val_vector;
    }

private:
    int val_int;
    vector<NestedInteger> val_vector;
    bool is_integer;
};