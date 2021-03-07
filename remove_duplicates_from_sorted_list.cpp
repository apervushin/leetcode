
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tail = head;
        ListNode* current = head;
        while (current != nullptr) {
            if (current->val != tail->val) {
                tail->next = current;
                tail = tail->next;

            }
            current = current->next;
            tail->next = nullptr;
        }
        return head;
    }
};

int main() {
    auto * head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution s;

    auto* result = s.deleteDuplicates(head);
    while (result != nullptr) {
        std::cout << result->val << ' ';
        result = result->next;
    }
    std::cout << '\n';

    return 0;
}
