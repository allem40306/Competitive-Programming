#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define M 100001

int main() {
		int t,i=0;
		cin>>t;
		for(;i<t;i++){
			vector <int> e[M]; 
			int n,m,a,b,u,v;
			scanf("%d %d %d %d",&n,&m,&a,&b);
			for(int i=0;i<m;i++){
				scanf("%d %d",&u,&v);
				e[u].push_back(v);
				e[v].push_back(u);
			}
			int d[M],c[M];
			memset(d,M,sizeof(d));
			memset(c,0,sizeof(c));	
			d[1]=0;
			for(int i=1;i<=n;i++){
				while(!e[i].empty()){
					int j=e[i].back();
					e[i].pop_back();
					d[j]=min(d[j],d[i]+a);
					if(i==1)c[i]=1;
				}
			}
			for(int i=2;i<=n;i++){
				if(c[i]==0)d[i]=min(d[i],d[i]+b);
			}
			for(int i=1;i<=n;i++){
				if(i>1)printf(" ");
				printf("%d",d[i]);
			}
			printf("\n");
		}
}
