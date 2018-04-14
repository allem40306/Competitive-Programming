#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,a[15]={1};
    for(int i=1;i<15;i++)a[i]=i*a[i-1];
    while(cin>>n){
        if(n<0){
            if(n&1){
                cout<<"Overflow!\n";
            }else{
                cout<<"Underflow!\n";
            }
        }else if(n>13){
            cout<<"Overflow!\n";
        }else if(a[n]<10000){
            cout<<"Underflow!\n";
        }else{
            cout<<a[n]<<'\n';
        }
    }
}
