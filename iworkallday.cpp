
#include <iostream>
#include <vector>
#include <limits>
 
using namespace std;
 
int main()
{
    int N;
    cin >> N;
 
    vector<int> A (N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
 
    int H;
    cin >> H;
 
    int smallest = numeric_limits<int>::max();
    int best = 0;
 
    for (int x : A) {
        if (H%x < smallest){
            best = x;
            smallest = H%x;
        }
    }
 
    cout << best;
 
    return 0;
}
