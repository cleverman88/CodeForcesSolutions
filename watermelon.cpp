//https://codeforces.com/contest/4/problem/A
#include <iostream>
#include <cstdlib>
 
using namespace std;
 
int main()
{
    int value;
    
    cin >> value;
    if(value == 2){
        cout << "NO";
    }
    else if(value % 2 == 1){
        cout << "NO";
    }
    
    else if(value % 2 == 0){
        cout << "YES";
    }
    
    return 0;
}
