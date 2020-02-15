#include<bits/stdc++.h>
using namespace std;

int ar[10005];
int fin(int x){
    int ans = 0;
    while(x){
        ans+=x&1;
        x =x >>1;
    }
    return ans;
}

int main(){
    int t , y , x;
    cin >> t;
    memset(ar,0,sizeof(ar));
    for(int i = 1 ;i < 10005 ; ++i)
        ar[i] = ar[i-1] + fin(i);

    while(t--){
        cin >> x >> y;
        cout << ar[y]-ar[x-1] << endl;
    }

}

