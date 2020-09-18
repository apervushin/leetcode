#include "tree_node.cpp"

using namespace std;

class PathSumIII {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return 0;
        }
        return pathSum(root, sum, 0) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

private:
    int pathSum(TreeNode* root, int sum, int currentSum) {
        if (root == nullptr) {
            return 0;
        }
        int cnt = 0;
        currentSum = currentSum + root->val;
        if (currentSum == sum) {
            cnt++;
        }
        cnt += pathSum(root->left, sum, currentSum);
        cnt += pathSum(root->right, sum, currentSum);

        return cnt;
    }
};