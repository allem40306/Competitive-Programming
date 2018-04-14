#include <bits/stdc++.h>
using namespace std;
#define N 200
#define P1 cout<<j<<' '<<sg[j]<<' '<<i-j-1<<' '<<sg[i-j-1]<<' '<<(sg[j]^sg[i-j-1])<<endl
#define P2 cout<<j<<' '<<sg[j]<<' '<<i-j-2<<' '<<sg[i-j-2]<<' '<<(sg[j]^sg[i-j-2])<<endl
unsigned long long sg[N+1],vis[N+1],sr[12]={2,8,1,4,7,2,1,8,2,7,4,1};
void init(){
	sg[0]=0;
	for(int i(1),v(1);i<=N;i++){
		v++;
		vis[sg[i-1]]=v;
		for(int j(1);j<=i-2;j++)
			vis[sg[j]^sg[i-j-1]]=v;
		vis[sg[i-2]]=v;
		for(int j(1);j<=i-3;j++)
			vis[sg[j]^sg[i-j-2]]=v;
		for(int j=0;j<N;j++){
			if(vis[j]!=v){
				sg[i]=j;
				break;
			}
		}
	}
}

int main(){
//	freopen("OwO.txt","w",stdout);
	init();
	unsigned long long t,ti=0,n,ni,x,y;
	for(cin>>t;ti<t;ti++){
		cin>>n>>x; x=(x>=N?sr[(x-74)%12]:sg[x]);
		for(ni=1;ni<n;ni++){
			cin>>y;
			x^=(y>=N?sr[(y-74)%12]:sg[y]);
		}
		cout<<(x?"F\n":"S\n");
	}
}
