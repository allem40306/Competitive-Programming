#include <bits/stdc++.h>
using namespace std;
const int N=105;
int main(){
    string s;
    int a[N];
    memset(a,0,sizeof(a));
    while(cin>>s,s!="0"){
//            cout<<s<<'\n';
        for(int i=0;i<s.size();i++){
            a[s.size()-1-i]+=(s[i]-'0');
        }
    }
    for(int i=0;i<N-1;i++){
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    int j=N-1;
    for(;!a[j];j--);
//    cout<<j<<'\n';
    for(;j>=0;j--){
        cout<<a[j];
    }
    cout<<'\n';
}
