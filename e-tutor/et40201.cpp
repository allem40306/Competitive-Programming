#include <iostream>
using namespace std;

void print(long long int n){
    cout<<n<<" =";
    for(int i=31;i>=0;i--){
        if(i%8==7)cout<<' ';
        cout<<((n>>i)&1);
    }
    cout<<" \n";
}


int main(){
    unsigned int n,m=0;
    cin>>n>>m;
    cout<<"number:\n";
    print(n);
    cout<<"\npow:\n";
    print(m);
    cout<<'\n'<<n<<" * "<<n<<'^'<<m<<" = "<<(n<<m)<<'\n';
    print(n<<m);
}

