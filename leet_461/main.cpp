#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int ret = 0;
        while (n) {
            if (n & 1) ret ++;
            n = n >> 1;
        }
        return ret;
    }
};

int main() {
    int x, y;
    Solution sln;
    while (cin>>x) {
        cin>>y;
        int ret = sln.hammingDistance(x,y);
        cout<<ret<<endl;
    }
    return 0;
}