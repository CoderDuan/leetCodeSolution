#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diffBits = 0;
        for (int i = 0; i < nums.size(); i++) {
            diffBits ^= nums[i];
        }

        int a = 0, b = 0;
        int lastDiffBit = (diffBits) & (-diffBits);
        for (int i = 0; i < nums.size(); i++) {
            if (lastDiffBit & nums[i]) a = a ^ nums[i];
            else b = b ^ nums[i];
        }
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        return v;
    }
};

int main() {
    Solution sln;
    return 0;
}