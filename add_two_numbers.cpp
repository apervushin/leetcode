#include "list_node.cpp"
using namespace std;

class AddTwoNumbers {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root {new ListNode};
        ListNode* current = root;
        int add_to_next = 0;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr) {
                current->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                current->val += l2->val;
                l2 = l2->next;
            }
            if (current->val >= 10) {
                add_to_next = current->val / 10;
                current->val %= 10;
            }
            if (l1 != nullptr || l2 != nullptr || add_to_next != 0) {
                current->next = new ListNode(add_to_next);
                current = current->next;
                add_to_next = 0;
            }
        }
        return root;
    }
};