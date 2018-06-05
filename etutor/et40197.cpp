#include <iostream>  
using namespace std;  
const int N=35;  
int main(){  
    long long int x,n=0,m,ti=1;  
    while(cin>>x,x!=-1){  
        n|=(1LL<<x);  
    }  
    for(int i=0;i<32;i++){  
        if((n>>i)&1)cout<<i<<' ';  
    }  
    cout<<'\n';  
    while(cin>>m){  
        cout<<"Case "<<ti++<<": "<<m<<'\n';  
        cout<<((n&m)==n?"true":"false")<<"(all bits 1)\n";  
        cout<<(n&m?"true":"false")<<"(exist bits 1)\n";  
    }  
}  