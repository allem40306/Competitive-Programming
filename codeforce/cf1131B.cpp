#include <bits/stdc++.h>
using namespace std;

int sol(int L, int R){
    static int RR = 0;
    int ret;
    // cout<<"de:"<<RR<<L<<R<<'\n';
    if(R < L)ret = 0;
    else{
        ret = R - L;
        if(L != RR)ret++;
    }
    RR = R;
    return ret;
}

int main(){
    int n, a = 0, b = 0;
    int ans = 1;
    cin>> n;
    for(int x, y; n; n--){
        cin >> x >> y;
        ans += sol(max(a, b), min(x, y));
        a = x;
        b = y;
    }
    cout << ans << '\n'; 
}