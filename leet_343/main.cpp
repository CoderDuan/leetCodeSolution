#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

#define ROUND(x) (int)((x-((int)x))>0.5f?((int)x)+1:(int)x)

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        int count = n / 3;
        int left = n % 3;
        if (left == 0)
            return pow(3, count);
        else if (left == 1)
            return pow(3, count-1)*4;
        else
            return pow(3, count)*2;
    }
};

int main() {
    Solution sln;
    for (int i = 0; i < 50; i++)
        //cout<<roundf(((float)i)*0.3f)<<endl;
        cout<<i<<'\t'<<sln.integerBreak(i)<<endl;
    return 0;
}