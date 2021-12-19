#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    long long a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        a--; b--; c--;
        long long ans=a^b^c;
        if(ans){
            cout<<"First\n";
        }else{
            cout<<"Second\n";
        }
    }
}