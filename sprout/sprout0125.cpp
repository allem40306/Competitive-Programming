#include <iostream>
using namespace std;
#define N 1000005
#define Mod 10000019
long long n,a[N],b[N];
long long mgs(long long L,long long R){
	if(L+1==R)return 0;
	long long M=(L+R)>>1;
	long long ans=(mgs(L,M)+mgs(M,R))%Mod;
	long long i=L,j=M,k=0,t=0;
	for(long long x=L;x<M;x++)t+=a[x];
	while(i<M||j<R){
		if(j==R){
			b[k++]=a[i++];
			t-=a[i];
		}
		else if(i==M)
			b[k++]=a[j++];
		else if(a[i]<=a[j]){
			t-=a[i];
			b[k++]=a[i++];
		}
		else{
			if(a[i]>a[j])
				ans=(ans%Mod+t+a[j]*(M-i)%Mod)%Mod;
			b[k++]=a[j++];
		}
	}
	for(long long kk=0;kk<k;kk++){
		a[L+kk]=b[kk];
	}
	return ans%Mod;
}
int main(){
	cin.tie(NULL);
	cin>>n;
	for(long long i=0;i<n;i++)
		cin>>a[i];
	cout<<mgs(0,n)<<'\n';
}
