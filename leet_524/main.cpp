#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ret = "";
        for(string str : d) {
            int strp = 0;
            int sp = 0;
            while (sp < s.length() && strp < str.length()) {
                if (s[sp] == str[strp]) {
                    strp ++;
                }
                sp ++;
            }
            if (strp == str.length()) {
                if (str.length() == ret.length())
                    if (str < ret)
                        ret = str;
                if (str.length() > ret.length())
                    ret = str;
            }
        }
        return ret;
    }
};

int main() {
    Solution sln;
    return 0;
}