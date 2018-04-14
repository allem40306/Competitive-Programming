#include <bits/stdc++.h>
using namespace std;
const int N=300000+5;
const int C=26+5;
const int MOD=20071027;
int trie[N][C],dp[N],val[N],sz;
string s,r;
//#define debug

void init(){
    sz=1;
    memset(trie[0],0,sizeof(trie[0]));
    dp[s.size()]=1;
    return;
}

void insert(){
    int u=0,v;
    for(int i=0;i<r.size();i++){
        v=r[i]-'a';
        if(!trie[u][v]){
            memset(trie[sz],0,sizeof(trie[sz]));
            val[sz]=0;
            trie[u][v]=sz++;
            #ifdef debug
                printf("trie[%d][%d]=%d\n",u,v,trie[u][v]);
            #endif // debug
        }
        u=trie[u][v];
    }
    #ifdef debug
        printf("~%d~\n",u);
    #endif // debug
    val[u]=1;
    return;
}

void search(int i){
    int u=0,v;
    dp[i]=0;
    for(int j=i;j<s.size();j++){
        v=s[j]-'a';
        #ifdef debug
            printf("%d->%d\n",u,v);
        #endif // debug
        if(!trie[u][v])return;
        u=trie[u][v];
        #ifdef debug
            printf("%d %d %d %d\n",u,val[u],i,j);
        #endif // debug
        if(val[u])dp[i]=(dp[i]+dp[j+1])%MOD;
    }
    return;
}

int main(){
    int n,ti=1;
    while(cin>>s){
        init();
        cin>>n;
        while(n--){
            cin>>r;
            insert();
        }
        for(int i=s.size()-1;i>=0;i--){
            search(i);
            #ifdef debug
                printf("%d %d\n",i,dp[i]);
            #endif // debug
        }
        cout<<"Case "<<ti++<<": "<<dp[0]<<'\n';
    }
    return 0;
}
