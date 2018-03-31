#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n>36){
        cout<<-1<<'\n';
        return 0;
    }
    while(n){
        if(n&1){
            cout<<'4';
            n-=1;
        }else{
            cout<<'8';
            n-=2;
        }
    }
    cout<<'\n';
}
