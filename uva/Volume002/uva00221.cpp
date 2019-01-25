#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n;
struct House{
    int id;
    double x,y,w,d,h;
    void in(){
        cin>>x>>y>>w>>d>>h;
    }
    bool operator<(const House&rhs)const{
        if(x!=rhs.x)return x<rhs.x;
        return y<rhs.y; 
    }
}a[N];

bool cover(int id,double mx){
    return a[id].x<=mx&&mx<=a[id].x+a[id].w;
}

bool visible(int id,double mx){
    if(!cover(id,mx))return false;
    for(int j=0;j<n;j++){
        if(a[j].y<a[id].y&&a[j].h>=a[id].h&&cover(j,mx))return false;
    }
    return true;
}

int main(){
    int ti=1;
    vector<double>v;
    while(cin>>n,n){
        v.clear();
        for(int i=0;i<n;i++){
            a[i].in();
            v.push_back(a[i].x);
            v.push_back(a[i].x+a[i].w);
            a[i].id=i+1;
        }
        sort(a,a+n);
        unique(v.begin(),v.end());
        sort(v.begin(),v.end());
        if(ti>1)cout<<'\n';
        cout<<"For map #"<<ti++<<", the visible buildings are numbered as follows:\n";
        cout<<a[0].id;
        for(int i=1;i<n;i++){
            for(int j=1;j<v.size();j++){
                if(visible(i,(v[j-1]+v[j])/2)){
                    cout<<" "<<a[i].id;
                    break;
                }
            }
        }
        cout<<'\n';
    }
}