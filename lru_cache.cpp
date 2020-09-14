#include <unordered_map>
#include <memory>

using namespace std;

class LRUCache {
public:
    explicit LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto find = cashared_ptrche.find(key);
        if (find == cache.end()) {
            return -1;
        }
        remove(find->second);
        add(find->second);
        return find->second->val;
    }

    void put(int key, int value) {
        auto find = cache.find(key);
        if (find != cache.end()) {
            find->second->val = value;
            remove(find->second);
            add(find->second);
        } else {
            if (capacity == cache.size()) {
                cache.erase(tail->key);
                remove(tail);
            }
            shared_ptr<Node> node = make_shared<Node>(key, value);
            add(node);
            cache.insert({key, node});
        }
    }

private:
    struct Node {
        int key;
        int val;
        shared_ptr<Node> prev = nullptr;
        shared_ptr<Node> next = nullptr;

        Node(int key, int val) : key(key), val(val) {}
    };

    int capacity;
    unordered_map<int, shared_ptr<Node>> cache;
    shared_ptr<Node> head = nullptr;
    shared_ptr<Node> tail = nullptr;

    void remove(shared_ptr<Node>& node) {
        if (node == head || node == tail) {
            if (node == head) {
                head = node->next;
            }
            if (node == tail) {
                tail = node->prev;
            }
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }

    void add(shared_ptr<Node>& node) {
        if (!head) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }
};
