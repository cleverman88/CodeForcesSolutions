//https://codeforces.com/contest/1191/problem/D

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
 
bool countRepeats(vector<int> arr) {
    int repeats = 0;
    unordered_map<int, int> mp;
    for (int a : arr) {
        mp[a] ++;
    }
    for (auto &x : mp) {
        if (x.second >= 2)
            repeats += x.second;
        if (x.first == 0 && x.second >= 2) {
            return true;
        }
    }
    if (repeats > 2)
        return true;
 
    for (auto &x : mp) {
        if (x.second == 2) {
            if (mp.find(x.first-1) != mp.end()) {
                return true;
            }
        }
    }
 
    return false;
}
 
int main() {
    // Gets inputs
 
    int N;
    cin >> N;
 
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
 
    if (N == 1) {
        if (arr[0] % 2 == 0) {
            cout << "cslnb";
            return 0;
        } else {
            cout << "sjfnb";
            return 0;
        }
        return 0;
    }
 
    if (countRepeats(arr)) {
        cout << "cslnb";
        return 0;
    }
 
    sort(arr.begin(), arr.end());
 
    int diff = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i]-i < 0) {
            cout << "sjfnb";
            return 0;
        }
        diff += arr[i]-i;
    }
 
    if (diff % 2 == 0) {
        cout << "cslnb";
        return 0;
    } else {
        cout << "sjfnb";
        return 0;
    }
 
    return 0;
}
