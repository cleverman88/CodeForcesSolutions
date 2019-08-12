https://codeforces.com/contest/339/problem/A

#include <iostream>
#include <cstdlib>
 
using namespace std;
 
int main()
{
    string input;
    cin >> input;
 
    int dp[3];
 
    for (int i = 0; i < 3; i++) {
        dp[i] = 0;
    }
 
    for (int i = 0; i < input.length(); i+=2) {
        dp[(input[i] - '0')-1]++;
    }
 
    string delim = "";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < dp[i]; j++) {
            cout << delim << i + 1;
            delim = "+";
        }
    }
 
    return 0;
}
