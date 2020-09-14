#include <queue>
#include <climits>
#include "tree_node.cpp"

using namespace std;

class MaximumLevelSumOfABinaryTree {
public:
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> queue;
        vector<int> result;
        result.push_back(INT_MIN);

        queue.push({root, 1});
        while (!queue.empty()) {
            auto node = queue.front();
            queue.pop();
            if (node.first == nullptr) {
                continue;
            }

            addResult(result, node.first->val, node.second);
            queue.push({node.first->left, node.second + 1});
            queue.push({node.first->right, node.second + 1});
        }

        int level = 1;
        for (int i = 1; i < result.size(); i++) {
            if (result[0] < result[i]) {
                result[0] = result[i];
                level = i;
            }
        }

        return level;
    }

private:
    void addResult(vector<int>& result, int val, int level) {
        if (result.size() == level) {
            result.push_back(val);
        } else {
            result[level] += val;
        }
    }
};
