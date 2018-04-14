#include <bits/stdc++.h>
using namespace std;
const int N=200;
//#define debug

int main(){
    int t,n,a[N][N]={},ans;
    cin>>t;
    while(t--){
        ans=-100;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
                a[i+n][j]=a[i][j+n]=a[i+n][j+n]=a[i][j];
            }
        }
        for(int i=1;i<=2*n;i++){
            for(int j=1;j<=2*n;j++){
                a[i][j]=a[i][j]+a[i][j-1]+a[i-1][j]-a[i-1][j-1];
                #ifdef debug
                    printf("%d ",a[i][j]);
                #endif // debug
            }
            #ifdef debug
                printf("\n");
            #endif // debug
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int h=0;h<n;h++){
                    for(int w=0;w<n;w++){
                        ans=max(ans,a[i+h][j+w]-a[i-1][j+w]-a[i+h][j-1]+a[i-1][j-1]);
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
}
