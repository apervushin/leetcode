#include "list_node.cpp"

class DeleteNodeInALinkedList {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev;

        while (node->next != nullptr) {
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        prev->next = nullptr;
        delete node;
    }
};