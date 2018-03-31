#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,n,s,v1,v2;
    string t,r;
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    while(cin>>n){
        a=b=0;
        cin>>t>>r;
        while(n--){
            cin>>s>>v1>>v2;
            if(v1>v2){
                a+=s;
            }else{
                b+=s;
            }
        }
        if(a>b){
            cout<<t<<'\n';
        }else if(a<b){
            cout<<r<<'\n';
        }else{
            cout<<"Tie\n";
        }
    }
}
