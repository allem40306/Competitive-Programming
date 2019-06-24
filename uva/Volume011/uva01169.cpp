#include <bits/stdc++.h>
using namespace std;
const int MXN = 100005;
int x[MXN], y[MXN], c[MXN];
int dp[MXN], f[MXN];
int SumOfDis[MXN], SumOfC[MXN];

int main(){
    int t, n, w;
    SumOfDis[0] = SumOfC[0] = x[0] = y[0] = c[0] = 0;
    cin >>  t;
    for(int ti = 0; ti != t; ++ti){
        cin >> w >> n;
        for(int i = 1; i <= n; i++){
            cin >> x[i] >> y[i] >> c[i];
            SumOfDis[i] = SumOfDis[i - 1] + abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
            SumOfC[i] = SumOfC[i - 1] + c[i];
        }
        deque<int>dq;
        dp[0] = 0;
        f[0] = dp[0] + (abs(x[1]) + abs(y[1])) - SumOfDis[1];
        dq.push_back(0);
        for(int i = 1; i <= n; i++){
            while(!dq.empty() && SumOfC[i] - SumOfC[dq.front()] > w)
                dq.pop_front();
            dp[i] = f[dq.front()] + SumOfDis[i] + (abs(x[i]) + abs(y[i]));
            if(i != n)f[i] = dp[i] + (abs(x[i + 1]) + abs(y[i + 1])) - SumOfDis[i + 1];
            while(!dq.empty() && f[dq.back()] >= f[i])
                dq.pop_back();
            dq.push_back(i);
        }
        if(ti)cout << '\n';
        cout << dp[n] << '\n';
    }
}