#include <bits/stdc++.h>
using namespace std;
const int N=55;
int R,C;
int SG[N][N];
bitset<N>is_up[N];

void build(){
    for(int i=0;i<N;i++)SG[i][0]=SG[0][i]=0;
    for(int r=1;r<N;r++)for(int c=1;c<N;c++){
        vector<int>v;
        for(int i=0;i<r;i++)for(int j=0;j<c;j++){
            v.push_back(SG[i][j]^SG[i][c]^SG[r][j]);
        }
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());
        for(int &x=SG[r][c]=0;x<v.size()&&x==v[x];x++);
    }
}

void sol(int v){
    for(int r=1;r<=R;r++)for(int c=1;c<=C;c++){
        if(!is_up[r][c])continue;
        for(int i=0;i<r;i++)for(int j=0;j<c;j++){
            if((SG[i][j]^SG[i][c]^SG[r][j]^SG[r][c])==v){
                cout<<r<<' '<<c<<'\n'<<i<<' '<<j<<'\n';
                return;
            }
        }
    }
}

int main(){
    freopen("coins.in","r",stdin);
    freopen("coins.out","w",stdout);
    build();
    while(cin>>R>>C){
        int ans=0;
        string s;
        for(int i=1;i<=R;i++){
            is_up[i].reset();
            cin>>s;
            for(int j=1;j<=C;j++){
                if(s[j-1]=='0')continue;
                is_up[i][j]=true;
                ans^=SG[i][j];
            }
        }
        if(ans){
            cout<<"Ann\n";
            sol(ans);
        }else{
            cout<<"Betty\n";
        }
    }
}