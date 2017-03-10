#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int top = numbers.size() - 1;
        int bottom = 0;
        while (top != bottom) {
            int sum = numbers[top] + numbers[bottom];
            if (sum > target) top --;
            else if (sum < target) bottom ++;
            else break;
        }
        vector<int> vec;
        vec.push_back(bottom+1);
        vec.push_back(top+1);
        return vec;
    }
};

int main() {
    Solution sln;
    return 0;
}