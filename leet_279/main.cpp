#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int dp[n+1] = {0};
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int min = dp[i-1] + 1;
            for (int j = 2; j*j <= i; j++) {
                if ((dp[i-j*j] + 1) < min)
                    min = dp[i-j*j] + 1;
            }
            dp[i] = min;
        }
        return dp[n];
    }
};

int main() {
    Solution sln;
    sln.numSquares(12);
    return 0;
}