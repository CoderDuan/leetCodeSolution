#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n : nums)
            sum += n;
        if (sum % 2 != 0)
            return false;
        else
            return f(nums, sum/2);
    }

    bool f(vector<int> &nums, int s) {
        bool dp[s+1] = {false};
        dp[0] = true;
        for (int n : nums) {
            for (int i = s; i >= n; i--) {
                dp[i] = dp[i] || dp[i-n];
            }
        }
        return dp[s];
    }
};

int main() {
    Solution sln;
    return 0;
}