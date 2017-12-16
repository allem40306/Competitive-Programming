#include <iostream>
using namespace std;
const int N=20005;
int main(){
    int t,n,a[N]={},ans,ansl,ansr;
    cin>>t;
    for(int ti=1;ti<=t;ti++){
        cin>>n;
        cin>>a[1];
        for(int i=2;i<n;i++){
            cin>>a[i];
            a[i]+=a[i-1];
        }
//        for(int i=0;i<=n;i++){
//            cout<<a[i]<<' ';
//        }cout<<'\n';
//        for(int i=1;i<n;i++)
//        {
//            cout<<i<<' '<<a[i]<<'\n';
//        }
        ans=ansl=ansr=0;
        for(int i=1;i<n;i++){
            for(int j=i;j<n;j++){
                if(a[j]-a[i-1]<0)break;
                if((a[j]-a[i-1]>0)&&(a[j]-a[i-1]>ans||(a[j]-a[i-1]==ans)&&(j-i+1>ansr-ansl))){
//                  cout<<i<<' '<<j<<' '<<a[j]-a[i-1]<<'\n';
                    ans=a[j]-a[i-1];
                    ansl=i;
                    ansr=j+1;
                }
            }
        }
//        cout<<ans<<'\n';
        if(!ans){
            cout<<"Route "<<ti<<" has no nice parts\n";
        }else{
            cout<<"The nicest part of route "<<ti<<" is between stops "<<ansl<<" and "<<ansr<<"\n";
        }
    }
}
