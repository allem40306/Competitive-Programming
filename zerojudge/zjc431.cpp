#include <bits/stdc++.h>
using namespace std;
const int N=105;
int main(){
    int n,x,c[N];
    cin>>n;
    memset(c,0,sizeof(c));
    for(int i=0;i<n;i++){
        cin>>x;
        c[x]++;
    }
    bool o=0;
    for(int i=1;i<=100;i++){
        while(c[i]){
            if(o)cout<<' ';
            o=1;
            cout<<i;
            c[i]--;
        }
    }
    cout<<'\n';
}
