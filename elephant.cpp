//https://codeforces.com/contest/617/problem/A

#include <iostream>
#include <cstdlib>
 
using namespace std;
 
int main()
{
    int value;
    cin >> value;
    
    if(value %5 == 0){
        cout << value/5;
    }
    else{
        cout << (value/5)+1;
    }
        
        return 0;
    }
