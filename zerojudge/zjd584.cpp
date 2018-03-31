#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,ans;
    while(cin>>n>>m){
        if(n==0){
            cout<<"0\n";
        }else if(n==2){
            cout<<(m-8)*3+(m>=8)+(m>=30)+(m>=70)+3*(m>=120)<<'\n';
        }else{
            cout<<(m-10)*3+(m>=10)+(m>=30)+(m>=70)+3*(m>=120)<<'\n';
        }
    }
}
