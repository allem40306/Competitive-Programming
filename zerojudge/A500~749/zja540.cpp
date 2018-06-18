#include <iostream>
using namespace std;
const int N=10005;
int main(){
    int n,a[N]={},ans;
    while(cin>>n,n){
        cin>>a[1];
        ans=a[1];
        for(int i=2;i<=n;i++){
            cin>>a[i];
            a[i]+=a[i-1];
        }
        for(int i=1;i<=n;i++){
            for(int j=i ;j<=n;j++){
//                cout<<i<<' '<<j<<' '<<a[j]-a[i-1]<<'\n';
                ans=max(ans,a[j]-a[i-1]);
            }
        }
        if(ans<=0){
            cout<<"Losing streak.\n";
        }else{
            cout<<"The maximum winning streak is "<<ans<<".\n";
        }
    }
}
