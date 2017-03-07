#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> tree;
    vector<TreeNode*> queue;
    int count;
public:
    int findBottomLeftValue(TreeNode* root) {
        count = 0;
        queue.push_back(root);
        parseTree();
        return tree[tree.size()-1];
    }

    void parseTree() {
        while (count < queue.size()) {
            TreeNode* node = queue[count];
            if (node) {
                tree.push_back(node->val);
                if (node->right)
                    queue.push_back(node->right);
                if (node->left)
                    queue.push_back(node->left);
            }
            count++;
        }
    }
};

int main() {
    Solution sln;
    return 0;
}