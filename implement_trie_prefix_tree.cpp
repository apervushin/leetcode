#include <string>
#include <unordered_map>
#include <memory>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */

    Trie() : root(make_shared<TrieNode>()) {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto current = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];

            auto find = current->childs.find(c);
            if (find == current->childs.end()) {
                find = current->childs.insert({c, make_shared<TrieNode>()}).first;
            }
            current = find->second;
        }
        current->is_final = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word) == FindResult::FOUND_FINAL;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != FindResult::NOT_FOUND;
    }

private:
    struct TrieNode {
        unordered_map<char, shared_ptr<TrieNode>> childs;
        bool is_final = false;
    };

    enum class FindResult {
        FOUND_NOT_FINAL,
        FOUND_FINAL,
        NOT_FOUND
    };

    shared_ptr<TrieNode> root;

    FindResult find(string& prefix) {
        auto current = root;
        for (int i = 0; i < prefix.length(); i++) {
            auto find = current->childs.find(prefix[i]);
            if (find == current->childs.end()) {
                return FindResult::NOT_FOUND;
            }
            current = find->second;
        }
        return current->is_final ? FindResult::FOUND_FINAL : FindResult::FOUND_NOT_FINAL;
    }
};