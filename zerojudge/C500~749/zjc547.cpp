#include <iostream>
using namespace std;

int main(){
    long long a[10005]={1,1},n;
    for(int i=2;i<10005;i++){
        a[i]=(a[i-1]+a[i-2])%1000000007;
    }
    while(cin>>n){
        cout<<a[n]<<'\n';
    }
}
