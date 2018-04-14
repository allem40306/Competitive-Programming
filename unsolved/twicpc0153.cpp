#include <iostream>
using namespace std;
int t,n,a[10],b[10],c[10],bi,cc;

void check(){
    for(int i=0;i<bi;i++){
        cc=0;
        if(b[i]>c[i])swap(b[i],c[i]);
        for(int j=b[i];j<=c[i];j++){
            if(j>b[j])cc++;
            if(cc>1||j==a[j]){
                cout<<"N\n";
                return;
            }
        }
    }
    cout<<"Y\n";
}

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        bi=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]!=i){
                b[bi]=i;
                c[bi++]=a[i];
            }
        }
        check();
    }
}
