#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProduct;
        vector<int> rightProduct;
        int leftCurr = 1;
        int rightCurr = 1;
        for (int i = 0; i < nums.size(); i++) {
            leftCurr *= nums[i];
            leftProduct.push_back(leftCurr);
            rightCurr *= nums[nums.size()-1-i];
            rightProduct.push_back(rightCurr);
        }
        vector<int> ret;
        ret.push_back(rightProduct[nums.size()-2]);
        for (int i = 1; i + 1 < nums.size(); i++) {
            ret.push_back(leftProduct[i-1] * rightProduct[nums.size()-i-2]);
        }
        ret.push_back(leftProduct[nums.size()-2]);
        return ret;
    }
};

int main() {
    Solution sln;
    return 0;
}