#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        cout<<2<<' '<<n<<' '<<n<<'\n';
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i<26)cout<<char('a'+i);
                else cout<<char('A'+i-26);
            }
            cout<<'\n';
        }
        cout<<'\n';
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j<26)cout<<char('a'+j);
                else cout<<char('A'+j-26);
            }
            cout<<'\n';
        }
    }
}