#include "list_node.cpp"

using namespace std;

class MergeTwoSortedLists {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        ListNode* root;
        ListNode* current;

        if (l1->val < l2->val) {
            current = l1;
            l1 = l1->next;
        } else {
            current = l2;
            l2 = l2->next;
        }
        current->next = nullptr;
        root = current;

        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                current->next = l2;
                return root;
            } else if (l2 == nullptr) {
                current->next = l1;
                return root;
            } else {
                if (l1->val < l2->val) {
                    current->next = l1;
                    l1 = l1->next;
                } else {
                    current->next = l2;
                    l2 = l2->next;
                }
                current = current->next;
            }
        }
        return root;
    }
};