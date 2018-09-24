#include <bits/stdc++.h> 
using namespace std;
#define N 30
struct loc{
	int x,y;
	loc(int x,int y):x(x),y(y){}
};
bool cmp(loc a,loc b){
	if(a.x!=b.x)return a.x<b.x;
	return a.y<b.y;
}
int main(){
	int n,m,t,ti=0,ai,ax,ay;
	string s[N];
	loc arr[N*N]=loc(0,0);
	for(cin>>t;ti<t;ti++){
		cin>>n>>m;
		ai=0;
		for(int i=0;i<n;i++)cin>>s[i];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(s[i][j]!='?'){
					arr[ai++]=loc(i,j);
				}
			}
		}
		sort(arr,arr+ai,cmp);
		for(int i=0;i<ai;i++){
			ax=arr[i].x;
			ay=arr[i].y;
			
		}
	}
}
