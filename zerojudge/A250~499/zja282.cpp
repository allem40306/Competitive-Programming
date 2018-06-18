#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    bitset<2005>b;
    while(cin>>n){
        b.reset();
        for(int i=0;i<n;i++){
            cin>>x;
            b[x]=1;
        }
        for(int i=1;;i++){
            if(b[i]==0){
                cout<<i<<'\n';
                break;
            }
        }
    }
}
