#include <vector>
#include <algorithm>
#include "list_node.cpp"

using namespace std;

class MergeKSortedLists {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root {nullptr};
        ListNode* current {nullptr};
        ListNode* tmp;
        make_heap(lists.begin(), lists.end(), greater1());
        while (!lists.empty()) {
            pop_heap(lists.begin(), lists.end(), greater1());
            tmp = lists.back();
            lists.pop_back();
            if(tmp == nullptr) {
                break;
            }
            if (current == nullptr) {
                current = tmp;
                root = current;
            } else {
                current->next = tmp;
                current = current->next;
            }
            tmp = tmp->next;
            current->next = nullptr;
            if (tmp != nullptr) {
                lists.push_back(tmp);
                push_heap(lists.begin(), lists.end(), greater1());
            }
        }
        return root;
    }

private:
    struct greater1{
        bool operator()(const ListNode* a, const ListNode* b) const{
            if (a == nullptr) {
                return true;
            }
            if (b == nullptr) {
                return false;
            }
            return a->val > b->val;
        }
    };
};