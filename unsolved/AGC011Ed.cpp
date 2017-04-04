#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(NULL);
	string s;
	cin>>s;
	int ans=1,len=s.size(),i,j;
	for(i=1;i<len;i++){
		if(s[i]<s[i-1]){
			ans++;
			j=i;
//			while(s[j])
			while(j>=2&&s[j-1]==s[j-2]){
				j--;
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
