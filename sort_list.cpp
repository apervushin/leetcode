#include "list_node.cpp"

using namespace std;

class SortList {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* a;
        ListNode* b;

        split(head, &a, &b);
        a = sortList(a);
        b = sortList(b);

        return mergeSorted(a, b);
    }

private:
    void split(ListNode* head, ListNode** a, ListNode** b) {
        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                fast = fast->next;
                slow = slow->next;
            }
        }

         *a = head;
        *b = slow->next;
        slow->next = nullptr;
    }

    ListNode* mergeSorted(ListNode* a, ListNode* b) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;

        while (a != nullptr || b != nullptr) {
            if (a == nullptr) {
                tail->next = b;
                b = b->next;
            } else if (b == nullptr) {
                tail->next = a;
                a = a->next;
            } else if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }

            tail = tail->next;
        }

        return head->next;
    }
};