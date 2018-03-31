#include <iostream>
using namespace std;
#define dtx(x) (x>9?char('A'+x-10):char('0'+x))
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    unsigned int ti=1,n;
    while(cin>>n){
        cout<<"Case "<<ti++<<": "<<n<<'\n';
        for(int i=7;i>=0;i--){
            cout<<dtx(int((n>>4*i)&15))<<' ';
        }
        cout<<'\n';
    }
}
