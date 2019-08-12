//https://codeforces.com/contest/1183/problem/A

#include <iostream>
#include <vector>
#define push_back DP
#define vector<int> VI
#define pair<int,int> PI
 
using namespace std;
 
int digitSum(int num) {
    int total = 0;
    while (num != 0) {
        total = total + num % 10;
        num /= 10;
    }
 
    return total;
}
 
int main()
{
    string S;
    cin >> S;
 
    int n = stoi(S);
 
    while ((digitSum(n)) % 4 != 0) {
        n++;
    }
 
    cout << n;
 
    return 0;
}
