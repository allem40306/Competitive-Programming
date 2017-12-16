#include <bits/stdc++.h>
using namespace std;
const int N=10005;

int main(){
    int t,n,h[N],w[N],dpi[N],dpd[N],ansi,ansd;
    cin>>t;
    for(int ti=1;ti<=t;ti++){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>h[i];
        }
        for(int i=0;i<n;i++){
            cin>>w[i];
            dpi[i]=dpd[i]=w[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(h[i]>h[j]){
                    dpi[i]=max(dpi[i],dpi[j]+w[i]);
                }
                if(h[i]<h[j]){
                    dpd[i]=max(dpd[i],dpd[j]+w[i]);
                }
            }
        }
        ansi=*max_element(dpi,dpi+n);
        ansd=*max_element(dpd,dpd+n);
        if(ansd>ansi){
            printf("Case %d. Decreasing (%d). Increasing (%d).\n",ti,ansd,ansi);
        }else{
            printf("Case %d. Increasing (%d). Decreasing (%d).\n",ti,ansi,ansd);
        }
    }
}
