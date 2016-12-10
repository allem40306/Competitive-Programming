#include <iostream>
#include <algorithm>
using namespace std;

struct map{
 int x,y;
 }p[1005];
 
bool comp (map a,map b){
     if(a.x!=b.x)
     return a.x<b.x;
     return a.y<b.y;
}
int main(){
    int n;
    while(cin>>n){
    for(int i=0;i<n;i++)
      cin>>p[i].x>>p[i].y;
    sort(p,p+n,comp);
    for(int i=0;i<n;i++)
    cout<<p[i].x<<" "<<p[i].y<<endl;
  }
}
