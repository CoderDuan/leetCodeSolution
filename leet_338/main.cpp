#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int max;
    vector<int> alreadyCounted;
public:
    Solution() {
        max = 0;
        alreadyCounted.push_back(0);
    }
    vector<int> countBits(int num) {
        vector<int> ret;
        if (num <= max) {
            for (int i = 0; i <= num; i++) {
                ret.push_back(alreadyCounted[i]);
            }
        } else {
            for (int i = 0; i <= max; i++) {
                ret.push_back(alreadyCounted[i]);
            }
            for (int i = max + 1; i <= num; i++) {
                int count = countBitsHelper(i);
                ret.push_back(count);
                alreadyCounted.push_back(count);
            }
        }
        return ret;
    }
    int countBitsHelper(int num) {
        if (num <= max)
            return alreadyCounted[num];
        else {
            return countBitsHelper(num/2) + num % 2;
        }
    }
};

int main() {
    Solution sln;
    int input;
    while(cin>>input) {
        vector<int> result = sln.countBits(input);
        for(int i = 0; i < result.size(); i++) {
            cout<<result[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}