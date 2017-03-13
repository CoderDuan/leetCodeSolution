#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1])
                return nums[i];
        }
        return 0;
    }
};

int f(int mat[][], int n, int d) {
    for (int i = 0; i < n; i++)
        cout<<mat[i][i]<<'\t';
    cout<<endl;
    return 666;
}

int main() {
    Solution sln;
    int n;
    cin>>n;
    int a[n][n] = {0};
    cout<<f(a, n, 2)<<endl;
    return 0;
}