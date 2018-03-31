#include <bits/stdc++.h>
using namespace std;
const int N=505;
int n,a[N][N],b[N][N],c[N][N],d[N][N];

void make_d(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j]=0;
            for(int k=0;k<n;k++){
                d[i][j]+=a[i][k]*b[k][j];
            }
//            cout<<d[i][j]<<' ';
        }
//        cout<<'\n';
    }
}

bool c_equal_to_d(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(c[i][j]!=d[i][j])return 0;
        }
    }
    return 1;
}

int main(){
    while(cin>>n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>b[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>c[i][j];
            }
        }
        make_d();
        if(c_equal_to_d()){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}
