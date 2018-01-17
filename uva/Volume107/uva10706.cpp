#include <bits/stdc++.h>
using namespace std;
const int N=400000;
long long int a[N]={},b[N]={},c=1;
void built(){
    int add=0,nol=0;
    for(int i=1;;i++){
        if(i==c){
            add++;
            c*=10;
        }
        b[i]=b[i-1]+add;
        nol+=add;
        a[i]=a[i-1]+nol;
        if(a[i]>=2147483647){
                return;
        }
    }
}
int main(){
    built();
    int t,n,x,v;
    cin>>t;
    while(t--){
        cin>>n;
        for(x=0;a[x]<n;x++);
        n-=a[x-1];
        for(x=0;b[x]<n;x++);
        v=x;
        for(int i=b[x]-n;i>0;i--){
            v/=10;
        }
        cout<<v%10<<'\n';
    }
}
