#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct road{
    int x,y;
};

bool cmp(road a,road b){
    if(a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;
}

int main(){
    int n,x,y,ans;
    road arr[10005];
    for(;cin>>n;){
            x=y=ans=0;
            for(int i=0;i<n;i++){
                    cin>>arr[i].x>>arr[i].y;
            }
            sort(arr,arr+n,cmp);
            for(int i=0;i<n;i++){
                    if(arr[i].x>=y){
                        ans+=y-x;
                        x=arr[i].x;
                        y=arr[i].y;
                    }else{
                        y=max(y,arr[i].y);
                    }
            }
            cout<<ans+y-x<<'\n';
    }
} 
