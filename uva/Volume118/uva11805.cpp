#include <iostream>
using namespace std;

int main(){
    int t,n,k,p;
    cin>>t;
    for(int ti=1;ti<=t;ti++){
        cin>>n>>k>>p;
        cout<<"Case "<<ti<<": "<<((k-1)+p)%n+1<<'\n';
    }
}
