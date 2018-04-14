#include <bits/stdc++.h>
using namespace std;
const int N=15;
long long int n,m,q,a[N],b[N];
vector<long long>ans;
//#define debug
void dfs(){
    int tmp;
    do{
        tmp=0;
        for(int i=0;i<n;i++){
            tmp+=a[i]*b[i];
        }
        ans.push_back(tmp);
    }while(next_permutation(b,b+n));
    return;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>q;
    for(int i=n-m;i<n;i++)b[i]=i-(n-m)+1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs();
    sort(ans.begin(),ans.end());
    #ifdef debug
        for(int i=0;i<ans.size();i++){
            printf("ans[%d]=%d\n",i,ans[i]);
        }
    #endif // debug
    long long x,y;
    for(int i=1;i<=q;i++){
        cin>>x;
        cout<<"Case #"<<i<<'\n';
        y=upper_bound(ans.begin(),ans.end(),x)-ans.begin();
        #ifdef debug
            printf("[%d]\n",y);
        #endif // debug
        if(y){
            cout<<ans[y-1]<<'\n';
        }else{
            cout<<"No Solution!\n";
        }
    }
}
