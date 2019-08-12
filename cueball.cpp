#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
 
#define PB push_back
#define PF push_front
#define iout(x) printf("%d\n",x)
#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define se second
#define fi first
 
typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;
typedef vector<ll> VLL;
typedef vector<int> VI;
 
const ll inf = 1e9+7;
 
string ballValues[] = {"red", "yellow", "green", "brown", "blue", "pink", "black"};
 
string findGreatestVal(unordered_map<string, int>& ballCounts) {
    for (int x = 6; x >= 0; x--)
        if (ballCounts[ballValues[x]] > 0) return ballValues[x];
    return "";
}
 
int ballPoints(string ball) {
    for (int x = 0; x < 8; x++)
        if (ballValues[x] == ball) return x+1;
    return 0;
}
 
void printBalls(unordered_map<string, int>& ballCounts) {
    for (auto &x : ballCounts) {
        cout << x.first << " " << x.second << "\n";
    }
}
 
int score(unordered_map<string, int> ballCounts, int N, bool prevRed) {
    int runningScore = 0;
    int remaining = N;
    while (remaining > 0) {
        if (ballCounts["red"] > 0) {
            // If there are red balls left
            if (prevRed) {
                // If the previous ball was red
                string b = findGreatestVal(ballCounts);
                if (b != "red") {
                    runningScore += ballPoints(b);
                } else {
                    // Only reds left
                    break;
                }
            } else {
                runningScore += ballPoints("red");
                ballCounts["red"]--;
                remaining--;
            }
            prevRed = !prevRed;
        } else {
            string c = findGreatestVal(ballCounts);
            runningScore += ballPoints(c);
            ballCounts[c]--;
            remaining--;
        }
    }
    return runningScore;
}
 
int main()
{
    // Inputs
    int N;
    cin >> N;
    unordered_map<string, int> ballCounts;
 
    string a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        ballCounts[a]++;
    }
 
    cout << max(score(ballCounts, N, true), score(ballCounts, N, false));
 
    return 0;
}
