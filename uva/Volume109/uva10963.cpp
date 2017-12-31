#include <bits/stdc++.h>
using namespace std;

int main(){
   int t,w,a,b,d;
   bool ok;
   cin>>t;
   for(int ti=0;ti<t;ti++){
        cin>>w>>a>>b;
        d=a-b;
        ok=1;
        for(int i=1;i<w;i++){
            cin>>a>>b;
            if(d!=a-b)ok=0;
        }
        if(ti)cout<<'\n';
        cout<<(ok?"yes\n":"no\n");
    }
}
