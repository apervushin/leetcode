#include <vector>
#include <algorithm>
#include "tree_node.cpp"

using namespace std;

class BinaryTreeZigzagLevelOrderTraversal {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        zigzagLevelOrder(root, 0);
        for (int i = 1; i < result.size(); i += 2) {
            reverse(result[i].begin(), result[i].end());
        }
        return result;
    }

private:
    vector<vector<int>> result;

    void zigzagLevelOrder(TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }
        add(root, depth);
        zigzagLevelOrder(root->left, depth + 1);
        zigzagLevelOrder(root->right, depth + 1);
    }

    void add(TreeNode* root, int depth) {
        if (depth >= result.size()) {
            result.push_back({root->val});
        } else {
            result[depth].push_back(root->val);
        }
    }
};