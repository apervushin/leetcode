#include "tree_node.cpp"

class FlattenBinaryTreeToLinkedList {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        flatten1(root);
    }

private:
    TreeNode* flatten1(TreeNode* root) {
        //cout << root->val << " -> ";
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = nullptr;
        TreeNode* tail = root;

        if (left != nullptr) {
            root->right = left;
            tail = flatten1(left);
        }
        if (right != nullptr) {
            tail->right = right;
            tail = flatten1(right);
        }
        return tail;
    }
};