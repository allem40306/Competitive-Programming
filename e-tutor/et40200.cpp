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
    cin>>n;
    for(int i=0;i<32;i++){
        m<<=1;
        m|=((n>>i)&1);
    }
    cout<<"Before bits are reversed:\n";
    print(n);
    cout<<"\nAfter bits are reversed:\n";
    print(m);
}
