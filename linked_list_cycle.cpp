#include "list_node.cpp"

class LinkedListCycle {
public:
    bool hasCycle(ListNode *head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (true) {
            if (p2 == nullptr || p2->next == nullptr) {
                return false;
            }

            p1 = p1->next;
            p2 = p2->next->next;

            if (p1 == p2) {
                return true;
            }
        }
    }
};