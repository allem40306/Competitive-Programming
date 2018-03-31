#include <iostream>
#include <cmath>
using namespace std;
const int N=1000005;
int n,x,a=0,b=0;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(i&1){
            a+=x;
        }else{
            b+=x;
        }
    }
    cout<<max(a,b)<<'\n';
}
