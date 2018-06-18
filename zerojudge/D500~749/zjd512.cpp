#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    set<LL>sb;
    set<LL>::iterator it;
    LL n,x;
    while(cin>>n){
        sb.clear();
        sb.insert(-1);
        sb.insert(0);
        for(int i=0;i<n;i++){
            cin>>x;
            it=sb.end();
            for(it--;it!=sb.begin();it--){
                if(sb.find(*it+x)==sb.end()){
                    sb.insert(*it+x);
                }
            }
        }
        cout<<sb.size()-2<<'\n';
    }
}
