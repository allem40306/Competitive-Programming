#include <iostream>
#include <algorithm>//upper_bound
using namespace std;
#define N 100005

int main(){
	int n, m, q, a[N],pos;
	cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++){
        cin >> q;
        pos=(upper_bound(a+1,a+n+1,q)-a)-1;
        if(a[pos]==q){
            cout<<pos<<'\n';
        }else{
            cout<<0<<'\n';
        }
    }
}
