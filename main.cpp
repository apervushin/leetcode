#include <iostream>
#include <string>
#include "binary_tree_zigzag_level_order_traversal.cpp"

using namespace std;

int main() {
    BinaryTreeZigzagLevelOrderTraversal s;
    TreeNode* in = new TreeNode(5);
    in->left = new TreeNode(1);
    in->right = new TreeNode(4);
    in->right->left = new TreeNode(3);
    in->right->right = new TreeNode(6);
    auto result = s.zigzagLevelOrder(in);
    for (auto r1 : result) {
        for (auto r2 : r1) {
            cout << r2 << " ";
        }
        cout << endl;
    }

    return 0;
}
