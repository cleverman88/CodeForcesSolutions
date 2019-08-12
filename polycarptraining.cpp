//https://codeforces.com/contest/1165/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int N;
    cin >> N;
 
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
 
    sort(A.begin(), A.end());
 
    int solved = 0;
    int problems = 1;
    for (auto x : A) {
        if (x >= problems) {
            solved++;
            problems++;
        }
    }
 
    cout << solved;
 
    return 0;
}
