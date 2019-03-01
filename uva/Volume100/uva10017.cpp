#include <bits/stdc++.h>
using namespace std;
int n, m, tot;
vector<int> h[3];

void init(int n){
    for(int i = 0; i < 3; i++)h[i].clear();
    for(int i = n; i; i--){
        h[0].push_back(i);
    }
}

void show(){
    cout << '\n';
    for(int i = 0; i < 3; i++){
        cout << char('A' + i) << "=>";
        if(h[i].size()){
            cout << "  ";
            for(int j = 0; j < h[i].size(); j++)cout << ' ' << h[i][j];
        }
        cout << '\n';
    }
}

void mov(int a, int c){
    int tmp = h[a].back(); h[a].pop_back();
    h[c].push_back(tmp);
    show();
    ++tot;
}

void hanoi(int d, int a, int b, int c){
//    cout << "de:" << d << ' ' << a << ' ' << b << ' ' << c << '\n';
    if(d == n)return;
    if(tot < m)hanoi(d + 1, a, c, b);
    if(tot < m)mov(a, c);
    if(tot < m)hanoi(d + 1, b, a, c);
}

int main(){
    int ti = 0;
    while(cin >> n >> m, n || m){
        init(n);
        tot = 0;
        cout << "Problem #" << ++ti << '\n';
        show();
        hanoi(0, 0, 1, 2);
        cout << '\n';
    }
}
