#include <stack>
#include "tree_node.cpp"

using namespace std;

class KthSmallestElementInABST {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> depth;
        int i = 1;

        while (root != nullptr || !depth.empty()) {
            if (root != nullptr) {
                depth.push(root);
                root = root->left;
            } else {
                root = depth.top();
                depth.pop();
                if (i++ == k) {
                    return root->val;
                }
                root = root->right;
            }
        }
        return -1;
    }
};
