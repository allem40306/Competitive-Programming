#include <bits/stdc++.h>
using namespace std;
const int N=305;
 
int main(){
    int n,a[N][N]={},s[N][N];
    while(cin>>n>>a[1][1]){
        s[1][1]=a[1][1];
        for(int i=2;i<=n;i++){
            s[i][1]=a[i][1]=a[1][1]+i;
        }
        for(int i=1;i<=n;i++){
            for(int j=2;j<=n;j++){
                a[i][j]=(a[i][j-1]*17)%103;
                if((i+j)&1)a[i][j]*=-1;
                s[i][j]=a[i][j]+s[i][j-1];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                int sum=0;
                for(int k=1;k<=n;k++){
                    if(sum<0)sum=0;
                    sum+=(s[k][j]-s[k][i-1]);
                    ans=max(ans,sum);
                }
            }
        }
        cout<<ans<<'\n';
    }
}