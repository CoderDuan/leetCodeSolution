#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<pair<int, int>> sumFreq;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;
        TreeSum(root);
        int maxFreq = 0;
        for (int i = 0; i < sumFreq.size(); i++) {
            if (sumFreq[i].second > maxFreq)
                maxFreq = sumFreq[i].second;
        }
        for (int i = 0; i < sumFreq.size(); i++) {
            if (sumFreq[i].second == maxFreq)
                ret.push_back(sumFreq[i].first);
        }
        return ret;
    }

    int TreeSum(TreeNode* node) {
        if (!node) return 0;
        int sum = node->val;
        sum += TreeSum(node->left);
        sum += TreeSum(node->right);

        bool found = false;
        for (int i = 0; i < sumFreq.size(); i++) {
            if (sumFreq[i].first == sum) {
                sumFreq[i].second ++;
                found = true;
            }
        }
        if (!found) {
            pair<int, int> newSum;
            newSum.first = sum;
            newSum.second = 0;
            sumFreq.push_back(newSum);
        }

        return sum;
    }
};

int main() {
    Solution sln;
    return 0;
}