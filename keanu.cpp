\\https://codeforces.com/contest/1189/problem/A
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int N;
    cin >> N;
 
    string S;
    cin >> S;
 
    if (N == 1 || count(S.begin(), S.end(), '1') != count(S.begin(), S.end(), '0')) {
        cout << 1 << "\n" << S;
        return 0;
    }
 
    for (int i = 0; i < N; i++) {
        string first = S.substr(0, i+1);
        string second = S.substr(i+1, N-i);
        if (count(first.begin(), first.end(), '1') != count(first.begin(), first.end(), '0') &&
            count(second.begin(), second.end(), '1') != count(second.begin(), second.end(), '0'))
             {
                cout << 2 << "\n";
                cout << first << " " << second;
                return 0;
            }
    }
 
    return 0;
}
