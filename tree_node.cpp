#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    friend ostream & operator << (ostream &out, const TreeNode *v) {
        if (v == nullptr) {
            return out;
        }
        out << "{" << v->val << ", ";
        if (v->left != nullptr) {
            out << v->left;
        } else {
            out << "x";
        }
        out << ", ";
        if (v->right != nullptr) {
            out << v->right;
        } else {
            out << "x";
        }
        out << "}";
        return out;
    }
};
