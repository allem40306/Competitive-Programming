#include <iostream>
#include <cstring>
using namespace std;
#define N 10010
#define M 1000000000
#define init(i) memset(i,0,sizeof(i))
#define minn(a,b) (a<b?a:b)
int a[N];

unsigned p(int L,int R){
	int i=1,j=L;
	unsigned pp=0;
	for(;i+j-1<=R;i++)
		pp+=i*a[j+i-1];
		//cout<<L<<' '<<R<<' '<<pp<<endl;
	return pp;
}

unsigned dp(int L,int R ,int k){
	if(k<=0||R-L<k+1)return p(L,R);
	unsigned ans=M;
	for(int i=L;i<R;i++){
		for(int j=1;j<=k;j++){
		ans=minn(ans,dp(L,i,k-j-1)+dp(i+1,R,j-1));
		//cout<<"a"<<ans<<endl;
		}
	}	
	return ans;
}

int main(){
	int t,n,k;
	while(cin>>t){
		while(t--){
			cin>>n>>k;
			init(a);
			for(int i=0;i<n;i++)cin>>a[i];
			for(int kk=0;kk<k;kk++)cout<<dp(0,n-1,kk)<<" ";
			cout<<endl;
			}
	}
}
