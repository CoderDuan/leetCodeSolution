#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> vec(nums.size(), 0);
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            if (vec[nums[i]-1] > 0) ret.push_back(nums[i]);
            else vec[nums[i]-1]++;
        }
        return ret;
    }
};

int main() {
    Solution sln;
    int array[] = {10,2,5,10,9,1,1,4,3,7};
    vector<int> vec = vector<int>(array, array + sizeof(array)/sizeof(int));
    vector<int> ret = sln.findDuplicates(vec);
    for (int i = 0; i < ret.size(); i++) {
        cout<<ret[i]<<'\t';
    }
    cout<<endl;
    return 0;
}