#include <bits/stdc++.h>
using namespace std;
long long pd[35]={1};
//#define debug
void init(){
    for(int i=1;i<35;i++){
        pd[i]=(pd[i-1]<<1);
    }
    return;
}

int main(){
    long long t,d,nd,nc,ans,vos[35];
    string s;
    priority_queue<int,vector<int>,greater<int>>pq;
    init();
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>d>>s;
        nc=nd=ans=0;
        memset(vos,0,sizeof(vos));
        for(int j=0;j<s.size();j++){
            if(s[j]=='C'){nc++;}
            else{vos[nc]++; nd+=pd[nc];}
        }
        #ifdef debug
            printf("nd:%lld\n",nd);
        #endif // debug
        while(nd>d){
            while(nc&&!vos[nc])nc--;
            if(!nc)break;
            #ifdef debug
                printf("%lld-%lld=%lld\n",nd,pd[nc]>>1,nd-(pd[nc]>>1));
            #endif // debug
            nd-=(pd[nc]>>1);
            vos[nc]--;
            vos[nc-1]++;
            ans++;
        }
        cout<<"Case #"<<i<<": ";
        if(nd<=d){
            cout<<ans<<'\n';
        }else{
            cout<<"IMPOSSIBLE\n";
        }
    }
    return 0;
}
