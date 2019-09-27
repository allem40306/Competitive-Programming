/*
source: ABC 116 B Collatz Problem
*/
#include <bits/stdc++.h>
using namespace std;
set<int> tb;

int main(){
    int n, stamp = 1;
    cin >> n;
    while(tb.find(n) == tb.end())
    {
        ++stamp;
        tb.insert(n);
        if(n & 1)
        {
            n = 3 * n + 1;
        }
        else
        {
            n = n / 2;
        }
    }
    cout << stamp << '\n';
}