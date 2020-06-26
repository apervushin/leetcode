#include <algorithm>
#include "tree_node.cpp"

using namespace std;

class MaximumDepthOfBinaryTree {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return result;
        }
        maxDepth(root, 0);
        return result;
    }

private:
    int result {0};

    void maxDepth(TreeNode* root, int depth) {
        if (root == nullptr) {
            result = max(result, depth);
            return;
        }
        maxDepth(root->left, depth + 1);
        maxDepth(root->right, depth + 1);
    }
};