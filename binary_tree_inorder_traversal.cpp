#include <vector>
#include <stack>
#include "tree_node.cpp"

using namespace std;

class BinaryTreeInorderTraversal {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> state;
        while (root != nullptr || !state.empty()) {
            if(root != nullptr) {
                state.push(root);
                root = root->left;
            } else {
                TreeNode* tmp = state.top();
                state.pop();
                result.push_back(tmp->val);
                root = tmp->right;
            }
        }
        return result;
    }
};