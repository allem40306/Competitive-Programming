#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define M 100005
#define gor(a,b) for(a=0;a<b;a++)

int main() {
	int t,i;
	cin>>t;
	gor(i,t){
		int n,m,g[M],f[M];
		cin>>n>>m;
		gor(i,n)cin>>g[i];
		gor(i,m)cin>>f[i];
		int q,l,r,v,go[M];//go(al)
		int gg[M],go
		memset(go,-1,sizeof(go));
		cin>>q;
		gor(i,q){
			cin>>l>>r>>v;
			for(int j=l;j<=r;j++){
				int pass[M]={0};
				if(g[f[j]-1]<=v){
				gg[f[j]-1]+=(i+1)*pass[[f[j]-1]];	
				pass[[f[j]-1]]=1;
				}
				gor(i,n){
					if(go[i]==-1&&go[i]>g[i])go[i]
				}
			}
		}
		gor(i,n){
			if(i)printf(" ");
			printf("%d",go[i]);
		}
		printf("\n");
	}
}
