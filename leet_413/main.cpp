#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.empty()) return 0;
        int ret = 0;
        for (int start = 0; start < A.size()-1;) {
            int delta = A[start+1] - A[start];
            int count = 0;
            for (int i = 2; start + i < A.size(); i++) {
                if (A[start+i] - A[start+i-1] == delta)
                    count ++;
                else
                    break;
            }
            ret += count*(count+1)/2;
            start += count+1;
        }
        return ret;
    }
};

int main() {
    Solution sln;
    int array[] = {1,2,3,8,9,10};
    vector<int> vec(array, array+sizeof(array)/sizeof(int));
    cout<<sln.numberOfArithmeticSlices(vec);
    return 0;
}