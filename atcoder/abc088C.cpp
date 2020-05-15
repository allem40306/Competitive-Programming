#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[3][3];
    bool ok=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i][j]-a[i][(j+1)%3]!=a[(i+1)%3][j]-a[(i+1)%3][(j+1)%3]){
                cout<<"No\n";
                return 0;
            }
            if(a[j][i]-a[(j+1)%3][i]!=a[j][(i+1)%3]-a[(j+1)%3][(i+1)%3]){
                cout<<"No\n";
                return 0;
            }
        }
    }
    cout<<"Yes\n";
}

