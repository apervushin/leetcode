#include <vector>

using namespace std;

class ValidateBinaryTreeNodes {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> nodes(n, -1);

        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1 && !join(i, leftChild[i], nodes)) {
                return false;
            }
            if (rightChild[i] != -1 && !join(i, rightChild[i], nodes)) {
                return false;
            }
        }

        for (int i : nodes) {
            if (i != -1) {
                n--;
            }
        }

        return n == 1;
    }

private:
    static int getParent(const int i, vector<int>& nodes) {
        int result = i;
        while (nodes[result] != -1) {
            result = nodes[result];
        }
        if (result != i) {
            nodes[i] = result;
        }
        return result;
    }

    static bool join(int i, int j, vector<int>& nodes) {
        i = getParent(i, nodes);
        j = getParent(j, nodes);
        if (i != -1 && i == j) {
            return false;
        }
        nodes[j] = i;
        return true;
    }
};