#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int middle = nums[nums.size()/2];
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            ret += abs(nums[i]-middle);
        }
        return ret;
    }
};

int main() {
    Solution sln;
    return 0;
}