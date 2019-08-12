//https://codeforces.com/contest/1061/problem/A

#include <iostream>
#include <cstdlib>
 
using namespace std;
 
int main()
{
    int value;
    int value2;
    cin >> value;
    cin >> value2;
    
    if(value2 %value == 0){
        cout << value2/value;
    }
    else{
        cout << (value2/value)+1;
    }
        
        return 0;
    }
