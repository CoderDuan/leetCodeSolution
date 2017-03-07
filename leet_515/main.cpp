#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    queue<TreeNode*> level;
    queue<TreeNode*> nextLevel;
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        if (root == NULL) return ret;
        ret.push_back(root->val);
        if (root->left)
            level.push(root->left);
        if (root->right)
            level.push(root->right);
        while(!level.empty()) {
            int max = level.front()->val;
            while(!level.empty()) {
                TreeNode* next = level.front();
                level.pop();
                if (next->val > max) max = next->val;
                if (next->left)
                    nextLevel.push(next->left);
                if (next->right)
                    nextLevel.push(next->right);
            }
            ret.push_back(max);
            level.swap(nextLevel);
        }
        return ret;
    }
};

int main() {
    Solution sln;
    return 0;
}