#include <bits/stdc++.h>
using namespace std;

int main(){
    bitset<40000>bi;
    int a,b,c;
    bool ok;
    while(cin>>a>>b>>c){
        bi.reset();
        bi[0]=1;
        for(int i=0;i<=2*c;i++){
            if(bi[i]){
                bi[i+a]=bi[i+b]=1;
            }
        }
        ok=1;
        for(int i=c;i<=2*c;i++){
            if(!bi[i]){
                ok=0;
                break;
            }
        }
        cout<<(ok?"Yes\n":"No\n");
    }
}
