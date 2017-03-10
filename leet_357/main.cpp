#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int a;
        if (n > 10)
            return count(10, a);
        else
            return count(n, a);
    }

    int count(int n, int &A) {
        if (n == 0) {
            A = 1;
            return 1;
        }
        if (n == 1) {
            A = 1;
            return 10;
        } else {
            int ret = count(n-1, A);
            A *= (11-n);
            return ret + 9*A;
        }
    }
};

int main() {
    Solution sln;
    for (int i = 0; i <= 10; i++) {
        cout<<i<<'\t'<<sln.countNumbersWithUniqueDigits(i)<<endl;
    }
    return 0;
}