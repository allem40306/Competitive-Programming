#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=105;
PII a[N];
vector<int>p;
int n,w,h;

void sol(){
    int ans=-1,ansx,ansy;
    int hh,ww;
    for(int i=0;i<p.size();i++){
        for(int j=i+1;j<p.size();j++){
            // cout<<p[i]<<'-'<<p[j]<<'\n';
            hh=p[j]-p[i];
            int curx=0;
            for(int k=0;k<n;k++){
                if(a[k].second<=p[i]||p[j]<=a[k].second)continue;
                ww=min(a[k].first-curx,hh);
                // cout<<curx<<' '<<a[k].first<<' '<<ww<<'\n';
                if(ans<ww){ans=ww; ansx=curx; ansy=p[i];}
                curx=a[k].first;
            }
            ww=min(w-curx,hh);
            // cout<<w<<' '<<curx<<' '<<ww<<'\n';
            if(ans<ww){ans=ww;  ansx=curx; ansy=p[i];}
        }
    }
    cout<<ansx<<' '<<ansy<<' '<<ans<<'\n';
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>w>>h;
        p.clear();
        for(int i=0;i<n;i++){
            cin>>a[i].first>>a[i].second;
            p.push_back(a[i].second);
        }
        sort(a,a+n);
        p.push_back(0);
        p.push_back(h);
        sort(p.begin(),p.end());
        p.resize(unique(p.begin(),p.end())-p.begin());
        if(i)cout<<'\n';
        sol();
    }
}