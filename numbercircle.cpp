//https://codeforces.com/contest/1189/problem/B

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
 
int getI(int i, int n) {
  return i % n;
}
 
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i ++) {
    int x;
    cin >> x;
    arr[i] = x;
  }
 
  sort(arr.begin(), arr.end());
 
 
  if (arr[n-1] >= arr[n-2] + arr[n-3]) {
    cout << "NO";
    return 0;
  }
int swaps;
  do {
    swaps = 0;
    for (int i = 0; i <= n; i ++) {
      if (arr[getI(i-1, n)] + arr[getI(i+1, n)] <= arr[getI(i, n)]) {
        //swap
        if (arr[getI(i-1, n)] > arr[getI(i+1, n)]) {
          // cout << i << " " << (i-1) << " " << endl;
          int tp = arr[getI(i-1, n)];
          arr[getI(i-1, n)] = arr[getI(i, n)];
          arr[getI(i, n)] = tp;
          if (arr[getI(i, n)] != arr[getI(i-1, n)])
            swaps ++;
        } else if (arr[getI(i-1, n)] < arr[getI(i+1, n)]){
          // cout << i << " " << (i+1) << " " << endl;
          int tp = arr[getI(i+1, n)];
          arr[getI(i+1, n)] = arr[getI(i, n)];
          arr[getI(i, n)] = tp;
          if (arr[getI(i, n)] != arr[getI(i+1, n)])
            swaps ++;
        }
      }
    }
 
    //for (auto x : arr)
    //  cout << x << " ";
    //cout << endl;
    //cout << swaps << endl;
  } while (swaps != 0);
 
      cout << "YES\n";
      for (auto x : arr)
        cout << x << " ";
      cout << endl;
      return 0;
 
  return 0;
}
