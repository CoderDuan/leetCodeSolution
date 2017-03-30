#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class City {
public:
	vector<int> neighbors;
	bool visited;
	City() {
		visited = false;
	}
};

bool valid(vector<City> &cityList, vector<int> &tour, int start, int toVisit) {
	City &thisCity = cityList[start];
	thisCity.visited = true;
	if (start == tour[toVisit])
		toVisit ++;
	if (toVisit == tour.size()) return true;
	int neighborsSize = thisCity.neighbors.size();
	for (int i = 0; i < neighborsSize; i++) {
		int nextCityNum = cityList[start].neighbors[i];
		if (cityList[nextCityNum].visited) continue;
		if (valid(cityList, tour, nextCityNum, toVisit)) {
			return true;
		}
	}
	thisCity.visited = false;
	return false;
}

int main() {
	int tcNum; // test case number
	cin>>tcNum;
	while (tcNum) {
		int cityNum;
		cin>>cityNum;
		vector<City> cityList;
		for (int i = 0; i < cityNum; i++) {
			City c;
			cityList.push_back(c);
		}
		for (int i = 0; i < cityNum-1; i++) {
			int city1, city2;
			cin>>city1>>city2;
			cityList[city1-1].neighbors.push_back(city2-1);
			cityList[city2-1].neighbors.push_back(city1-1);
		}
		int tourSize;
		cin>>tourSize;
		vector<int> tour;
		for (int i = 0; i < tourSize; i++) {
			int city;
			cin>>city;
			tour.push_back(city-1);
		}
		if (valid(cityList, tour, tour[0], 0))
			cout<<"YES\n";
		else
			cout<<"NO\n";
		tcNum --;
	}
    return 0;
}