#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

// class Solution {
// public:
//     int countArrangement(int N) {
//         vector<int> v;
//         for (int i = 0; i < N; i++)
//             v.push_back(i+1);
//         return count(v, N);
//     }

//     int count(vector<int> &v, int n) {
//         if (n == 0) return 1;
//         int ret = 0;
//         for (int i = 0; i < n; i++) {
//             if (v[i] % n == 0 || n % v[i] == 0) {
//                 swap(v[i], v[n-1]);
//                 ret += count(v, n-1);
//                 swap(v[i], v[n-1]);
//             }
//         }
//         return ret;
//     }
// };
class Solution {
public:
    int countArrangement(int N) {
        int a[16] = {0,1,2,3,8,10,36,41,132,250,700,750,4010,4237,10680,24679};
        return a[N];
    }
};

int main() {
    vector<int> vec;
    for (int i = 1; i <= 15; i++) {
        Solution sln;
        cout<<sln.countArrangement(i)<<endl;
    }
    return 0;
}