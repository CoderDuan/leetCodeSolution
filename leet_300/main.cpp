#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size < 1)
            return 0;
        if (size == 1) return 1;
        int array[size] = {1};
        int maxLen = 0;
        for (int i = 1; i < size; i++) {
            int max = 0;
            int last = nums[i];
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    if (array[j] > max) {
                        max = array[j];
                        last = nums[j];
                    }
                }
            }
            array[i] = max + 1;
            if (array[i] > maxLen)
                maxLen = array[i];
        }
        return maxLen;
    }
};

int main() {
    Solution sln;
    return 0;
}