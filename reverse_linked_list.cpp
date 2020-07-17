#include "list_node.cpp"

using namespace std;

class ReverseLinkedList {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* result {nullptr};
        ListNode* tmp;
        while (head != nullptr) {
            tmp = head->next;
            head->next = result;
            result = head;
            head = tmp;
        }
        return result;
    }
};