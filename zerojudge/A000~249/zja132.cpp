#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,ans;
    string s;
    while(cin>>n,n){
        s="";
        ans=0;
        while(n){
            s=((n%2)?"1":"0")+s;
            if(n%2)ans++;
            n/=2;
        }
        cout<<"The parity of "<<s<<" is "<<ans<<" (mod 2).\n";
    }
}
