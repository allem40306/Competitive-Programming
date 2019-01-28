#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
	Point() {};
	Point(int x, int y): x(x), y(y) {}
	bool operator <(const Point& b)const {return x != b.x ? x < b.x : y < b.y;}
	bool operator ==(const Point& b)const {return x == b.x && y == b.y;}
	Point operator -(const Point& b)const {return Point(x - b.x, y - b.y);}
	int cross(const Point& b)const {return x * b.y - y * b.x;}
	int dis(Point a, Point b) {return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);}
};

struct Kingdom{
    bool is_destory;
    vector<Point>p,p1;
    Kingdom(){
        is_destory=false;
    }
    void bulid(int n){
        for(int i=0,x,y;i<n;i++){
            cin>>x>>y;
            p.push_back(Point{x,y});
        }
        sort(p.begin(),p.end());
        p.resize(unique(p.begin(),p.end())-p.begin());
    }
    void convexhull(){
        p1.resize(p.size());
        int m=0;
        for(int i=0;i<p.size();i++){
            while(m>1&&(p1[m-1]-p1[m-2]).cross(p[i]-p1[m-2])<=0)m--;
            p1[m++]=p[i];
        }
        int k=m;
        for(int i=p.size()-2;i>=0;i--){
            while(m>k&&(p1[m-1]-p1[m-2]).cross(p[i]-p1[m-2])<=0)m--;
            p1[m++]=p[i];
        }
        if(m>1)m--;
        p1.resize(m);
    }
    void destory(Point a){//(a)ttack
        if(is_destory)return;
        for(int i=1;i<p1.size();i++){
            if((p1[i]-p1[i-1]).cross(a-p1[i-1])<0)return;
        }
        is_destory=true;
    }
    double getArea(){
        if(!is_destory)return 0;
        double ret=0;
        for(int i=1;i<p1.size();i++){
            ret+=p1[i-1].cross(p1[i]);
        }
        ret+=p1[p1.size()-1].cross(p1[0]);
        return ret/2;
    }
};

int main(){
    int n,tot=0;
    vector<Kingdom>vk;
    vk.clear();
    while(cin>>n,n!=-1){
        Kingdom k;
        vk.push_back(k);
        vk[tot].bulid(n);
        vk[tot].convexhull();
        tot++;
        // cout<<n<<'\n';
    }
    int x,y;
    while(cin>>x>>y){
        Point missile=Point{x,y};
        for(int i=0;i<vk.size();i++){
            vk[i].destory(missile);
        }
    }
    double area=0;
    for(int i=0;i<vk.size();i++){
        area+=vk[i].getArea();
    }
    cout<<fixed<<setprecision(2)<<area<<'\n';
    return 0;
}