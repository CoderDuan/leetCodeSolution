#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        vector<string> v;
        for (int i = 0; i < s.length(); i++) {
            bool found = false;
            for (int j = 0; j < v.size(); j++) {
                if (s[i] == v[j][0]) {
                    v[j] += s[i];
                    found = true;
                    break;
                }
            }
            if (!found) {
                string str = "";
                str += s[i];
                v.push_back(str);
            }
        }

        sort(v.begin(), v.end(), compare);

        string ret = "";
        for (int i = 0; i < v.size(); i++) {
            ret += v[i];
        }
        return ret;
    }

    static bool compare(string &a, string &b) {
        return (a.length() > b.length());
    }
};

int main() {
    Solution sln;
    string s = "";
    cout<<"!!!"<<s+'a'<<endl;
    cout<<sln.frequencySort("tree")<<endl;
    return 0;
}