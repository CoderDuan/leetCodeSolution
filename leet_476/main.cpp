#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int complement = ~num;
        int mask = ~0;
        while (num) {
            num = num >> 1;
            mask = mask << 1;
        }
        return complement ^ mask;
    }
};

int main() {
    Solution sln;
    int num;
    while (cin>>num) {
        cout<<sln.findComplement(num)<<endl;
    }
    return 0;
}