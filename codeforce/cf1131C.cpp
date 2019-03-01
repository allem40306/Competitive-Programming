#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int>v,w;
    cin >> n;
    w.resize(n);
    for(int i = 0, x;i < n;i++){
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int pos = n / 2, d = 1;
    w[pos] = v[--n];
    while(n){
        if(pos - d >= 0){
            w[pos - d]= v[--n];
        }
        if(pos + d < w.size()){
            w[pos + d]= v[--n];
        }
        d++;
    }
    for(int i=0;i<w.size();i++){
        if(i)cout<<' ';
        cout<<w[i];
    }
    cout<<'\n';
}