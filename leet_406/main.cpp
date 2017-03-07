#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
        vector<pair<int, int> > ret;
        int start = 0;
        int end = 0;
        sort(people.begin(), people.end(), numberOperator);
        sort(people.begin(), people.end(), heightOperator);
        //printPeople(people);
        while (start < people.size() && end < people.size()) {
            for (; end < people.size(); end++) {
                int count = 0;
                for (int i = 0; i < start; i++) {
                    if (people[i].first >= people[end].first)
                        count ++;
                }
                if (count == people[end].second)
                    break;
            }
            //cout<<start<<'\t'<<end<<endl;
            if (start != end) {
                iter_swap(people.begin() + start, people.begin() + end);
                //printPeople(people);
                sort(people.begin() + start+1, people.begin() + end+1, heightOperator);
                //printPeople(people);
            }
            start ++;
            end = start;
        }

        return people;
    }

    static bool heightOperator(pair<int, int> &a, pair<int, int> &b) {
        return (a.first < b.first);
    }

    static bool numberOperator(pair<int, int> &a, pair<int, int> &b) {
        return (a.second < b.second);
    }

    void printPeople(vector<pair<int, int> >& people) {
        cout<<'[';
        for(int i = 0; i < people.size(); i++) {
            cout<<'['<<people[i].first<<','<<people[i].second<<"],";
        }
        cout<<']'<<endl;
    }
};

int main() {
    Solution sln;
    return 0;
}