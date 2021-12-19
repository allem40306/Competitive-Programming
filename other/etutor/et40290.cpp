#include <iostream>
using namespace std;
#define dtx(x) (x>9?char('A'+x-10):char('0'+x))
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    unsigned int x,n=0;
    while(cin>>x){
        n|=(1<<x);
    }
    cout<<n<<'\n'<<"0x";
    bool o=0;
    for(int i=7;i>=0;i--){
        if(!o&&((n>>4*i)&15)==0)continue;
        o=1;
        cout<<dtx(int((n>>4*i)&15));
    }
    if(!n)cout<<n;
    cout<<'\n';
}
