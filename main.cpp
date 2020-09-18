#include <iostream>
#include <vector>
#include "flatten_binary_tree_to_linked_list.cpp"

using namespace std;

int main() {
    FlattenBinaryTreeToLinkedList s;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    s.flatten(root);
    cout << root;

    return 0;
}