#include <iostream>
#include <vector>
#include "diameter_of_binary_tree.cpp"

using namespace std;

int main() {
    DiameterOfBinaryTree s;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << s.diameterOfBinaryTree(root);

    return 0;
}