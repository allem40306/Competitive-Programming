#include <bits/stdc++.h>
using namespace std;
const long long int N=65005;
bool b[N]={1,1,0};
void build(){
    for(int i=2;i<N;i++){
        if(!b[i]){
            for(int j=2*i;j<N;j+=i){
                b[j]=1;
            }
        }
    }
}

long long mod(long long a,long long n,long long mm){
//    cout<<a<<' '<<d<<' '<<n<<'\n';
    if(n==0)return 1;
    if(n==1)return a;
    long long M=mod(a,n/2,mm);
    if(n%2){
        return ((M*M)%mm)*a%mm;
    }else{
        return (M*M)%mm;
    }
}

bool ok(long long n){
    int M;
    for(long long i=2;i<n;i++){
        M=mod(i,n,n);
//        cout<<i<<' '<<M<<'\n';
        if(i!=M)return 0;
    }
    return 1;
}

int main(){
    build();
    long long int n;
    while(cin>>n,n){
        if(b[n]&&ok(n)){
            cout<<"The number "<<n<<" is a Carmichael number.\n";
        }else{
            cout<<n<<" is normal.\n";
        }
    }
}
