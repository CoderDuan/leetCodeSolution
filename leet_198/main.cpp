#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0];

        int array[nums.size()] = {0};
        array[0] = nums[0];
        array[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            array[i] = max(array[i-2] + nums[i], array[i-1]);
        }
        return max(array[nums.size() - 2], array[nums.size() - 1]);
    }
};

int main() {
    Solution sln;
    return 0;
}