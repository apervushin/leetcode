#include <vector>
#include <stack>
#include "tree_node.cpp"

using namespace std;

class BinaryTreeLevelOrderTraversal {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        levelOrder(root, 0);
        return result;
    }

private:
    vector<vector<int>> result;

    void levelOrder(TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }
        add(depth, root->val);
        levelOrder(root->left, depth + 1);
        levelOrder(root->right, depth + 1);
    }

    void add(int pos, int val) {
        if (result.size() > pos) {
            result[pos].push_back(val);
        } else {
            result.push_back({val});
        }
    }
};