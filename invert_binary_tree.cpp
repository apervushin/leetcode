#include "tree_node.cpp"

class InvertBinaryTree {
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }

private:
    void invert(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        invert(root->left);
        invert(root->right);
        swap(root->left, root->right);
    }
};