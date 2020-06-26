#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    friend ostream & operator << (ostream &out, const ListNode *v) {
        if (v == nullptr) {
            return out;
        }
        out << v->val;
        if (v->next != nullptr) {
            out << " -> " << v->next;
        }
        return out;
    }
};
