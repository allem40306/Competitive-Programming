#include <iostream>
using namespace std;
int a[505][505];	

int main(){
	int n,m,x,y,z,w;
	while(cin>>n>>m){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
				a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
			}
		}
		for(int i=0;i<m;i++){
			cin>>x>>y>>z>>w;
			cout<<a[z][w]+a[x-1][y-1]-a[x-1][w]-a[z][y-1]<<'\n';
		}
	}
}
