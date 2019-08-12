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
 
double helper(int numberUp, int N, int rK, vector<vector<double>>& cache) {
    if (rK <= 0) {
        return (double)numberUp;
    }
    if (cache[rK][numberUp] != -1) {
        return cache[rK][numberUp];
    }
 
    double r;
    if (numberUp < N) {
        // If not all are up
        r = (helper(numberUp, N, rK-1, cache) + helper(numberUp+1, N, rK-1, cache))/2.0;
    } else {
        r = (helper(numberUp-1, N, rK-1, cache) + helper(numberUp, N, rK-1, cache))/2.0;
    }
    cache[rK][numberUp] = r;
    return r;
}
 
int main()
{
    int N, K;
    cin >> N >> K;
 
    vector<vector<double>> cache(K+1, vector<double>(N+1, -1));
 
    printf("%.7f", helper(0, N, K, cache));
    
    return 0;
}
