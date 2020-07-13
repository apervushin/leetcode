#include <iostream>
#include <string>
#include "symmetric_tree.cpp"

using namespace std;

int main() {
    SymmetricTree s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode();
    cout << s.isSymmetric(root);
    return 0;
}
