#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,y;
    cin>>n>>y;
    y/=1000;
    for(int i=0;i<=n;i++){
        for(int j=0;j+i<=n;j++){
            if((10*i+5*j+(n-i-j)==y)&&(n-i-j)>=0){
                cout<<i<<' '<<j<<' '<<n-i-j<<'\n';
                return 0;
            }
        }
    }
    cout<<"-1 -1 -1\n";
}
