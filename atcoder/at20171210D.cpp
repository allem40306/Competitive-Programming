#include <bits/stdc++.h>
using namespace std;
const int N=55;
int n,a[N],h=0;//head
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(abs(a[i])>abs(a[h]))h=i;
    }
    cout<<2*n-1<<'\n';
    for(int i=0;i<n;i++){
        cout<<h+1<<' '<<i+1<<'\n';
    }
    if(a[h]>0){
        for(int i=0;i<n-1;i++){
            cout<<i+1<<' '<<i+2<<'\n';
        }
    }else{
        for(int i=n;i>1;i--){
            cout<<i<<' '<<i-1<<'\n';
        }
    }
}
