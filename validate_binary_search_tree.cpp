#include <climits>
#include <stack>
#include "tree_node.cpp"

using namespace std;

class ValidateBinarySearchTree {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode* prev = nullptr;

        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }

            TreeNode* tmp = stack.top();
            stack.pop();
            if (prev != nullptr && prev->val >= tmp->val) {
                return false;
            }
            prev = tmp;
            root = tmp->right;
        }
        return true;
    }

private:
    bool isValidBSTRecursion(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode* root, long min_val, long max_val) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= min_val || root->val >= max_val) {
            return false;
        }
        bool result = isValidBST(root->left, min_val, root->val);
        if (result) {
            result = isValidBST(root->right, root->val, max_val);
        }
        return result;
    }
};