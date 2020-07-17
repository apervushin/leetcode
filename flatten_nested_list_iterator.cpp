#include <vector>
#include <stack>
#include "nested_integer.cpp"

using namespace std;

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (NestedInteger &ni : nestedList) {
            process(ni);
            iterator = result.begin();
        }
    }

    int next() {
        int i = *iterator;
        ++iterator;
        return i;
    }

    bool hasNext() {
        return iterator != result.end();
    }

private:
    vector<int> result;
    vector<int>::iterator iterator;
    
    void process(NestedInteger &ni) {
        if(ni.isInteger()) {
            result.push_back(ni.getInteger());
        } else {
            for (NestedInteger ni1 : ni.getList()) {
                process(ni1);
            }
        }
    }
};
