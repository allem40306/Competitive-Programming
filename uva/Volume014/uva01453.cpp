#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int dx[4]={0,0,1,1},dy[4]={0,1,0,1};
struct loc{
    int x,y;
    loc(){};
    loc(int x,int y):x(x),y(y){}
};

bool operator <(const loc& a,const loc& b){
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}
bool operator ==(const loc& a,const loc& b){
    return a.x==b.x&&a.y==b.y;
}
loc operator -(loc a,loc b){
    return loc(a.x-b.x,a.y-b.y);
}
vector<loc>p,p1;
int n;
int cross(loc a,loc b){
    return a.x*b.y-a.y*b.x;
}
void convexhull(){
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    p1.clear();
    p1.resize(p.size());
    int m=0;
    for(int i=0;i<p.size();i++){
        while(m>1&&cross(p1[m-1]-p1[m-2],p[i]-p1[m-2])<=0)m--;
        p1[m++]=p[i];
//        cout<<m-1<<' '<<p1[m-1].x<<' '<<p1[m-1].y<<'\n';
    }
    int k=m;
    for(int i=p.size()-2;i>=0;i--){
        while(m>k&&cross(p1[m-1]-p1[m-2],p[i]-p1[m-2])<=0)m--;
        p1[m++]=p[i];
//        cout<<m-1<<' '<<p1[m-1].x<<' '<<p1[m-1].y<<'\n';
    }
    if(n>1)m--;
    p1.resize(m);
}

int dis(loc a,loc b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int sol(){
    if(p1.size()==1)return 0;
    if(p1.size()==2)return dis(p1[0],p1[1]);
    p1.push_back(p1[0]);
    int ans=0;
    for(int u=0,v=1;u<p1.size()-1;u++){
        while(1){
            int difc=cross(p1[u+1]-p1[u],p1[v+1]-p1[v]);
            if(difc<=0){
                ans=max(ans,dis(p1[u],p1[v]));
                if(difc==0)ans=max(ans,dis(p1[u],p1[v+1]));
                break;
            }
            v=(v+1)%(p1.size()-1);
        }
    }
    return ans;
}

int main(){
    int t,x,y,r;
    cin>>t;
    for(int ti=0;ti<t;ti++){
        cin>>n;
        p.clear();
        for(int i=0;i<n;i++){
            cin>>x>>y>>r;
            for(int j=0;j<4;j++){
                p.push_back(loc(x+dx[j]*r,y+dy[j]*r));;
            }
        }
        convexhull();
//        for(auto a:p1){
//            cout<<a.x<<'_'<<a.y<<'\n';
//        }
        cout<<sol()<<'\n';
    }
}
