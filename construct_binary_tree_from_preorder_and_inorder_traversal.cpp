#include <vector>
#include <unordered_map>
#include "tree_node.cpp"

using namespace std;

class ConstructBinaryTreefromPreorderAndInorderTraversal {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_positions;
        int pos {0};
        for (size_t i {0}; i < inorder.size(); i++) {
            inorder_positions[inorder[i]] = i;
        }
        return buildTree(preorder, inorder, 0, preorder.size() - 1, inorder_positions, pos);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end,
            unordered_map<int, int>& inorder_positions, int& pos) {
        if (start > end) {
            return nullptr;
        }
        TreeNode* node {new TreeNode(preorder[pos])};
        int inorder_pos {inorder_positions[preorder[pos++]]};
        node->left = buildTree(preorder, inorder, start, inorder_pos - 1, inorder_positions, pos);
        node->right = buildTree(preorder, inorder,inorder_pos + 1, end, inorder_positions, pos);
        return node;
    }
};