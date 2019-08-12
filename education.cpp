#include <iostream>
#include <vector>
#include <algorithm>
 
typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;
typedef vector<ll> VLL;
typedef vector<int> VI;
 
const int inf = numeric_limits<int>::max();
 
struct building {
    int capacity, rent, index, inUse;
};
 
struct dept {
    int size, index;
};
 
bool compare(building i, building j) {
    return i.capacity > j.capacity;
}
 
bool compare2(dept i, dept j) {
    return i.size < j.size;
}
 
int main()
{
    int n, m;
    cin >> n >> m;
 
    vector<dept> departments(n);
    vector<building> buildings(m);
 
    for (int i = 0; i < n; i++) {
        cin >> departments[i].size;
        departments[i].index = i;
    }
 
    for (int i = 0; i < m; i++) {
        cin >> buildings[i].capacity;
        buildings[i].index = i;
        buildings[i].inUse = false;
    }
 
    for (int i = 0; i < m; i++) {
        cin >> buildings[i].rent;
    }
 
    sort(departments.begin(), departments.end(), compare2); // Sort departments by size ascending
    sort(buildings.begin(), buildings.end(), compare); // Sort buildings by capacity
 
    vector<int> indicesToOutput(n);
 
    for (int d = n-1; d >= 0; d--) {
        int minCostBuilding = -1;
        int minCost = inf;
        for (int b = 0; b < m; b++) {
            if (buildings[b].capacity < departments[d].size) {
                // Capacity too small
                break;
            }
            if (!buildings[b].inUse) {
                if (buildings[b].rent < minCost) {
                    minCostBuilding = b;
                    minCost = buildings[b].rent;
                } else if (buildings[b].rent == minCost && buildings[b].capacity > buildings[minCostBuilding].capacity) {
                    minCostBuilding = b;
                    minCost = buildings[b].rent;
                }
            }
        }
        if (minCost < inf && minCostBuilding >= 0) {
            indicesToOutput[departments[d].index] = buildings[minCostBuilding].index+1;
            buildings[minCostBuilding].inUse = true;
        } else {
            cout << "impossible";
            return 0;
        }
    }
    for (auto x : indicesToOutput) {
        cout << x << " ";
    }
    return 0;
}
