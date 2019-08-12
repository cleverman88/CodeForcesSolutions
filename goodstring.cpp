//https://codeforces.com/contest/1165/problem/C
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
 
using namespace std;
 
int main()
{
    int N;
    cin >> N;
 
    string S;
    cin >> S;
 
    unordered_set<int> delIndices;
    int deletes = 0;
    int i = 0;
    while (i < N) {
        if (i == N-1) {
            delIndices.insert(i);
            deletes++;
            break;
        }
 
        if (S[i] != S[i+1]) {
            i += 2;
        } else {
            delIndices.insert(i);
            deletes++;
            i++;
        }
    }
 
    cout << deletes << "\n";
 
    for (int i = 0; i < N; i++) {
        if (!delIndices.count(i))
            cout << S[i];
    }
 
    return 0;
}
