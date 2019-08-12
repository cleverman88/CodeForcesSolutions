//https://codeforces.com/contest/1191/problem/A
#include <stdio.h>
#include <iostream>
using namespace std;
 
int main() {
    int N;
    cin >> N;
 
    int r = N % 4;
 
    switch (r) {
        case 0:
            cout << "1 A";
            return 0;
        case 1:
            cout << "0 A";
            return 0;
        case 2:
            cout << "1 B";
            return 0;
        case 3:
            cout << "2 A";
            return 0;
    }
}
