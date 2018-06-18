#include <iostream>
using namespace std;

int main(){
    int n,ans=0,x,y;
    bool u=0,d;
    cin>>n>>x;
    for(int i=1;i<n;i++){
        cin>>y;
        if(x==y)continue;
        if(x<y){
            u=1;
        }else{
            if(u)ans++;
            u=0;
        }
        x=y;
    }
    cout<<ans<<'\n';
}
