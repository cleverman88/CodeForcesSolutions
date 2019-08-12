#include <iostream>
#include <vector>
#include <algorithm>
#include <istream>
#include <sstream>
#include <string>
#include <unordered_map>
 
typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;
typedef vector<ll> VLL;
typedef vector<int> VI;
 
const ll inf = 1e9+7;
 
 
int main(){
    ll N;
    cin >> N;
    vector<ll> sweets(3);
    for(ll i = 0; i < N; i++){
        cin >> sweets[0];
        cin >> sweets[1];
        cin >> sweets[2];
        ll sum = sweets[0]+ sweets[1] + sweets[2];
        if(sum % 2 == 0){
            cout << sum/2 << endl;
        }
        else{
            cout << (sum-1)/2 << endl;
        }
    }
    return 0;
}
