//https://codeforces.com/contest/1183/problem/D
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int N;
    cin >> N;
 
    for (int i = 0; i < N; i++) {
        int T;
        cin >> T;
 
        unordered_map<int,int> m;
        for (int j = 0; j < T; j++) {
            int x;
            cin >> x;
            m[x]++;
        }
 
        vector<int> ordered;
        for (const auto &myPair : m) {
            ordered.push_back(myPair.second);
        }
 
        sort(ordered.begin(), ordered.end(), greater<int>());
 
        int lowest = ordered[0] - 1;
        int total = lowest;
        int index = 1;
        while (lowest > 0 & index < ordered.size()) {
            if (lowest <= ordered[index]) {
                total += lowest;
                index++;
            } else {
                lowest = ordered[index];
                total += lowest;
                index++;
            }
            lowest--;
        }
 
        cout << total+1 << "\n";
    }
}
