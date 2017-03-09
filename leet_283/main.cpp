#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         sort(nums.begin(), nums.end(), compare);
//     }

//     static bool compare(int &a, int &b) {
//         if (b == 0) return true;
//         return false;
//     }
// };

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < nums.size();) {
            if (nums[i] == 0)
                nums.erase(nums.begin() + i);
            else
                i++;
        }
        for (int i = nums.size(); i < size; i++) {
            nums.push_back(0);
        }
    }
};

int main() {
    Solution sln;
    return 0;
}