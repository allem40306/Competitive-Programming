#include <bits/stdc++.h>
using namespace std;
#define N 1000
int k,ans,zero,len;
string s;
int main(){
	cin>>s>>k;
	len=s.size();
	for(len--;len>=0;len--){
		if(s[len]=='0')
			zero++;
		else
			ans++;
		if(zero>=k){
			cout<<ans<<endl;
			return 0;
		}
	}
	cout<<ans+zero-1<<endl;
}
