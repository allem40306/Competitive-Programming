#include <bits/stdc++.h>
using namespace std;
const int MXN = 55;
vector<int> sticks;
bitset<MXN> used;
int sum, len;

bool ok(int i, int sz, int remain){
    // cout << i << ' ' << sz << ' ' << remain << '\n';
    if(sz == 0){
        remain -= len;
        if(remain == 0)return true;
        for(i = 0 ; used[i] ; ++i)
            ;
        used[i] = 1;
        if(ok(i + 1, len - sticks[i], remain))return true;
        used[i] = 0;
        remain += len;
    }else{
        for(int j = i; j < (int)sticks.size(); ++j){
            if(j > 0 && sticks[j] == sticks[j - 1] && !used[j - 1])continue;
            if(!used[j] && sz >= sticks[j]){
                used[j] = 1;
                if(ok(j + 1, sz - sticks[j], remain))return true;
                used[j] = 0;
                if(sticks[j] == sz)break;
            }
        }
    }
    return false;
}

void solve(int n){
    for(len = sticks[0]; len <= sum / 2; ++len){
        if(sum % len)continue;
        if(ok(0, len, sum)){
            cout << len << '\n';
            return;
        }
    }
    cout << sum << '\n';
}

void init(int n){
    sum = 0;
    sticks.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> sticks[i];
        sum += sticks[i];
    }
    used.reset();
    sort(sticks.begin(), sticks.end(), greater<int>());
}

int main(){
    int n;
    while(cin >> n, n){
        init(n);
        solve(n);
    }
}
