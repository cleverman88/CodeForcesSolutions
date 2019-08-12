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
 
const ll inf = 1e9+7;
 
struct planet {
    int hoursInDay, sunrise, sunset;
};
 
int main()
{
    int N;
    cin >> N;
    vector<planet> planets(N);
    int longestDay = 0;
 
    for (int i = 0; i < N; i++) {
        cin >> planets[i].hoursInDay >>planets[i].sunrise >> planets[i].sunset; 
        if (planets[i].hoursInDay > longestDay) {
            longestDay = planets[i].hoursInDay;
        }
    }
 
    int presidentHours = 1825*longestDay;
    int t;
 
    for (int hour = 0; hour < presidentHours; hour++) {
        bool everyoneOK = true;
        for (planet p : planets) {
            t = hour % p.hoursInDay;
            if (p.sunrise < p.sunset) {
                if (p.sunrise < t && t < p.sunset) {
                    everyoneOK = false;
                }
            } else {
                if (!(p.sunset <= t && t <= p.sunrise)) {
                    everyoneOK = false;
                }
            }
        }
        if (everyoneOK) {
            cout << hour;
            return 0;
        }
    }
    cout << "impossible";
    
    return 0;
}
