#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=10005;

int main()
{
    LL k,n,m,f,a[N],mn=0;
    while(cin>>k>>n>>m>>f)
    {
        for(int i=0;i<k;i++)
        	cin>>a[i];

        sort(a,a+k);

        LL p=1+(k-1)*f,ans=0;
        for(int i=0;i<k;i++,p-=f)
        {
            if(p<=m)break;
            ans+=(p-m)*a[i];
        }
        cout<<ans<<'\n';
    }
}
