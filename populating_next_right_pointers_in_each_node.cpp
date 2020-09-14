#include "node.cpp"

class PopulatingNextRightPointersInEachNode {
public:
    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        connect(root, nullptr);
        return root;
    }

private:
    void connect(Node* root, Node* next) {
        root->next = next;
        if (!root->right) {
            return;
        }
        connect(root->right, next ? next->left : nullptr);
        connect(root->left, root->right);
    }
};