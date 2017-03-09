#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = (int)sqrt(area);
        for (; w > 0; w--) {
            if (area % w == 0)
                break;
        }
        vector<int> ret;
        ret.push_back(area/w);
        ret.push_back(w);
        return ret;
    }
};

int main() {
    Solution sln;
    return 0;
}