#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int n : nums)
            sum += n;
        if (sum < S)
            return 0;
        if ((S + sum) % 2 != 0)
            return 0;
        else
            return f(nums, (S + sum)/2);
    }

    int f(vector<int> &nums, int s) {
        int dp[s+1] = {0};
        dp[0] = 1;
        for (int n : nums) {
            for (int i = s; i >= n; i--) {
                dp[i] += dp[i-n];
            }
        }
        return dp[s];
    }
};

int main() {
    Solution sln;
    int array[5] = {1, 1, 1, 1, 1};
    vector<int> v(array, array + sizeof(array)/sizeof(int));
    cout<<sln.findTargetSumWays(v, 3)<<endl;
    return 0;
}