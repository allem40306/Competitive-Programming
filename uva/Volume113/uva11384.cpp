#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        cout << floor(log2(n)) + 1 << '\n';
    }
}