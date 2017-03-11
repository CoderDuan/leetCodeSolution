#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        long long int maxFlag = (1 << size) - 1;
        vector<vector<int>> ret;
        for (long long int i = 0; i <= maxFlag; i++) {
            vector<int> v;
            for (int j = 0; j < size; j++) {
                if ((i & (1 << j))) {
                    v.push_back(nums[j]);
                }
            }
            ret.push_back(v);
        }
        return ret;
    }
};

int main() {
    Solution sln;
    return 0;
}