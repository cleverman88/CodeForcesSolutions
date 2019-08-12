\\https://codeforces.com/contest/1180/problem/A

#include <iostream>
 
using namespace std;
 
int main()
{
    int N;
    cin >> N;
 
    int c = 1;
 
    for (int i = 0; i < N; i++) {
        c+=4*i;
    }
 
    cout << c;
 
    return 0;
}
