#include "tree_node.cpp"

class SerializeandDeserializeBinaryTree {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        serializeDFS(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return deserializeDFS(data, i);
    }

private:
    const char open_bracket = '{';
    const char close_bracket = '}';

    void serializeDFS(TreeNode* root, string& result) {
        result.push_back(open_bracket);
        if (root != nullptr) {
            result.append(to_string(root->val));
            serializeDFS(root->left, result);
            serializeDFS(root->right, result);
        }
        result.push_back(close_bracket);
    }

    TreeNode* deserializeDFS(const string& data, int& pos) {
        int i = pos + 1;
        if (data[i] == '}') {
            pos = i + 1;
            return nullptr;
        }

        while (data[i] == '-' || (data[i] >= '0' && data[i] <= '9')) {
            i++;
        }
        TreeNode* root = new TreeNode(stoi(data.substr(pos + 1, i - pos - 1)));
        pos = i;
        root->left = deserializeDFS(data, pos);
        root->right = deserializeDFS(data, pos);
        pos += 1;
        return root;
    }
};
