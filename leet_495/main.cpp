#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     int findPoisonedDuration(vector<int>& timeSeries, int duration) {
//         int total = 0;
//         for (int i = 0; i + 1 < timeSeries.size(); i++) {
//             int dt = timeSeries[i+1] - timeSeries[i];
//             total += min(dt, duration);
//         }
//         if (timeSeries.size() > 0) total += duration;
//         return total;
//     }
// };

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0) return 0;
        int total = duration;
        int posionStart = timeSeries[0];
        int posionEnd = timeSeries[0] + duration;
        for (int i = 0; i < timeSeries.size(); i++) {
            if (timeSeries[i] < posionEnd)
                posionStart = timeSeries[i];
            else {
                total += posionStart + duration - posionEnd;
                posionEnd = posionStart + duration;
                if (posionEnd < timeSeries[i]) {
                    posionStart = timeSeries[i];
                    total += duration;
                    posionEnd = posionStart + duration;
                } else {
                    posionStart = timeSeries[i];
                }
            }
        }
        if (posionStart + duration > posionEnd) {
            total += posionStart + duration - posionEnd;
        }
        return total;
    }
};

int main() {
    Solution sln;
    int array[] = {};
    vector<int> vec(array, array + sizeof(array)/sizeof(int));
    cout<<sln.findPoisonedDuration(vec, 10000)<<endl;
    return 0;
}