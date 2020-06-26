#include <iostream>
#include <string>
#include "construct_binary_tree_from_preorder_and_inorder_traversal.cpp"

using namespace std;

int main() {
    ConstructBinaryTreefromPreorderAndInorderTraversal s;
    //vector<int> pre {3,9,20,15,7};
    //vector<int> in {9,3,15,20,7};
    //vector<int> pre {1, 2};
    //vector<int> in {1, 2};
    vector<int> pre {3, 1, 2, 4};
    vector<int> in {1, 2, 3, 4};
    auto result = s.buildTree(pre, in);
    cout << result <<endl;
    return 0;
}
