#include <iostream>
using namespace std;
const int N=300005;
 
int main(){
    int n,a[N];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m=n;
    for(int i=n-1;i>=0;i--){
        if(a[i]==m){
            m--;
        }
    }
    cout<<m<<'\n';
}