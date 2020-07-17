#include <stack>
#include "tree_node.cpp"

using namespace std;

class LowestCommonAncestorOfABinaryTree {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, State>> stack;
        stack.push(pair<TreeNode*, State>(root, State::INIT));
        TreeNode* result = nullptr;

        while (!stack.empty()) {
            auto tmp = stack.top();
            stack.pop();
            if (tmp.first == nullptr) {
                continue;
            }

            if (tmp.second == State::INIT) {
                tmp.second = State::LEFT_PASSED;
                stack.push(tmp);
                stack.push(pair<TreeNode*, State>(tmp.first->left, State::INIT));

                if (tmp.first == q || tmp.first == p) {
                    if (result != nullptr) {
                        return result;
                    } else {
                        result = tmp.first;
                    }
                }
            } else if (tmp.second == State::LEFT_PASSED) {
                tmp.second = State::BOTH_PASSED;
                stack.push(tmp);
                stack.push(pair<TreeNode*, State>(tmp.first->right, State::INIT));
            } else {
                if (result != nullptr && result == tmp.first) {
                    result = stack.top().first;
                }
            }
        }
        return nullptr;
    }

private:
    enum class State {
        INIT,
        LEFT_PASSED,
        BOTH_PASSED
    };
};