#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
unsigned long long n,ans=1;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=M;
	}
	cout<<ans<<endl;
} 
