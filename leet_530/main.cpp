#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
    vector<int> tree;
public:
    int getMinimumDifference(TreeNode* root) {
        constructTree(root);
        int min = tree[1] - tree[0];
        for (int i = 0; i + 1 < tree.size(); i++) {
            int delta = tree[i+1] - tree[i];
            if (delta < min)
                min = delta;
        }
        return min;
    }

    void constructTree(TreeNode* node) {
        if (node->left)
            constructTree(node->left);
        tree.push_back(node->val);
        if (node->right)
            constructTree(node->right);
    }
};

int main() {
    Solution sln;
    return 0;
}