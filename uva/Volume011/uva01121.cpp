#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, s, a[N];

int main(){
    while(cin >> n >> s){
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
            a[i] += a[i - 1];
        }
        int ans = n + 1;
        for(int i = 1, j = 1; i <= n && j <= n;){
            if(a[j] - a[i - 1] < s){
                j++;
            }else{
                ans = min(ans, j - i + 1);
                i++;
            }
        }
        if(ans == n + 1)cout << "0\n";
        else cout << ans << '\n';
    }
}