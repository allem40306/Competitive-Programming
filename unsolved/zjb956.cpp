#include <bits/stdc++.h>
using namespace std;
#define N 100000
int arr[N][2],t,ti=0,n,ma,mb,k,a,b,u,v;
bool vis[N];
vector<int> x[N],y[N];
void bfsx(int i,int s){
    arr[s][0]=i;
    if(vis[s]||i>=k+1)return;    
	vis[s]=1;
	printf("x[%d]=%d",s,i);
	int lens=x[s].size();
    for(int j=0;j<lens;j++)
        bfsx(i+1,x[s][j]);
}
void bfsy(int i,int s){
    arr[s][1]=i;
    if(vis[s]||i>=k+1)return;    
	vis[s]=1;
	printf("y[%d]=%d",s,i); 
    int lens=y[s].size();
	for(int j=0;j<lens;j++)
        bfsy(i+1,y[s][j]);
}
bool ddd(int k,int n){
    for(int i=0;i<n;i++){
	        if(arr[i][0]&&arr[i][1]&&max(arr[i][0],arr[i][1])<=k+1)
            return 1;
    }
    return 0;
}

void init(){
	for(int i=0;i<N;i++){
		x[i].clear();
		y[i].clear(); 
	}	 
}
int main(){
    for(cin>>t;ti<t;ti++){
    	init();
        cin>>n>>ma>>mb>>k>>a>>b;
        memset(arr,0,sizeof(arr));
        for(int i=0;i<ma;i++){
            cin>>u>>v;
            x[u].push_back(v);  
        }for(int i=0;i<mb;i++){
            cin>>u>>v;
            y[u].push_back(v);
        }
		memset(vis,0,sizeof(a));
		bfsx(1,a);
		memset(vis,0,sizeof(a));
		bfsy(1,b); 
		if(ddd(k,n))cout<<"Yes.\n";
        else cout<<"No.\n";
    }
}
