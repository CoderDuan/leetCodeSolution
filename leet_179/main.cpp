#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(const string &a, const string &b) {
    return (a+b)>(b+a);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (auto i : nums) {
            v.push_back(to_string(i));
        }
        sort(v.begin(), v.end(), compare);
        string ret = "";
        for (int i = 0; i < v.size(); i++) {
            ret += v[i];
        }
        int i;
        for (i = 0; i < ret.length() - 1; i++) {
            if (ret[i] != '0') break;
        }
        return ret.substr(i, ret.length() - i);
    }
};

int main() {
    Solution sln;
    return 0;
}