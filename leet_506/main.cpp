#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct Info {
    int id;
    int score;
    string title;
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ret;
        if (nums.size() <= 0) return ret;
        vector<Info> v;
        for (int i = 0; i < nums.size(); i++) {
            Info info;
            info.id = i;
            info.score = nums[i];
            info.title = "";
            v.push_back(info);
        }

        sort(v.begin(), v.end(), compareScore);

        if (v.size() > 0) v[0].title = "Gold Medal";
        if (v.size() > 1) v[1].title = "Silver Medal";
        if (v.size() > 2) v[2].title = "Bronze Medal";

        for (int i = 3; i < v.size(); i++) {
            v[i].title = to_string(i+1);
        }

        sort(v.begin(), v.end(), compareId);
        for (int i = 0; i < v.size(); i++) {
            ret.push_back(v[i].title);
        }
        return ret;
    }

    static bool compareScore(Info &a, Info &b) {
        return (a.score > b.score);
    }

    static bool compareId(Info &a, Info &b) {
        return (a.id < b.id);
    }
};

int main() {
    Solution sln;
    return 0;
}