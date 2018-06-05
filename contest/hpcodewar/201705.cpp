#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define N 1000
int n,a[N][N],dp[N][N];
bool b[N][N];
bool is(int i){
	for(int j=2;j*j<=i;j++)
		if(i%j==0)return 0;
	return 1;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			b[i][j]=is(a[i][j]);
			}
	}
	int i=0,j=0,ans=0;
	while(1){
		ans+=a[i][j];
		if(i==n-1&&j==n-1)break;
		if(i+1==n||!b[i+1][j])j++;
		else if(j+1==n||!b[i][j+1])i++;
		else if(a[i+1][j]<a[i][j+1])i++;
		else j++;
	}
	cout<<ans<<'\n'; 
}
