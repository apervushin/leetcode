#include <queue>
#include "list_node.cpp"

class RemoveNthNodeFromEndOfList {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return head;
        }

        ListNode* l1 = head;
        ListNode* l2 = head;
        int cnt {0};
        while (l1 != nullptr) {
            l1 = l1->next;
            if (cnt > n) {
                l2 = l2->next;
            }
            ++cnt;
        }
        if (l2 == head && cnt == n) {
            head = l2->next;
        } else {
            l2->next = l2->next->next;
        }
        return head;
    }
};