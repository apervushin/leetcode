#include <vector>
#include "tree_node.cpp"

using namespace std;

class ConvertSortedArraytoBinarySearchTree {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int startPos, int endPos) {
        if (startPos > endPos) {
            return nullptr;
        }
        int midPos = startPos + ((endPos - startPos) / 2);
        TreeNode* root = new TreeNode(nums[midPos]);
        root->left = sortedArrayToBST(nums, startPos, midPos - 1);
        root->right = sortedArrayToBST(nums, midPos + 1, endPos);
        return root;
    }
};