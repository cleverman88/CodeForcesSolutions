#include <iostream>
#include <unordered_map>
 
using namespace std;
 
 
 
int main()
{
    unordered_map<int,double> NOTES;
    NOTES[0] = 2;
    NOTES[1] = 1;
    NOTES[2] = (double)1/2;
    NOTES[4] = (double)1/4;
    NOTES[8] = (double)1/8;
    NOTES[16] = (double)1/16;
 
    int N;
    cin >> N;
 
    double output = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        output += NOTES[x];
    }
 
    printf("%.7f",output);
 
    return 0;
}
