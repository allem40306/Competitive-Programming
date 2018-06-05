#include <bits/stdc++.h>
using namespace std;

int main(){
    bool b[50]={};
    int x,n,c,t;
    for(int i=0;i<10;i++){
        cin>>x;
        b[x]=1;
    }
    cin>>t;
    while(t--){
        c=0;
        for(int i=0;i<6;i++){
            cin>>x;
            c+=b[x];
        }
        if(c>=3){
            cout<<"Lucky\n";
        }else{
            cout<<"Unlucky\n";
        }
    }
}
