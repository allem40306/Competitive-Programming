#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,ni=0,ans=0;
	string s;
	for(cin>>n;ni<n;ni++){
		cin>>s;
		if(s[2]==s[3]&&s[4]==s[5])
				ans+=s[3]==s[4]?2000:1500;
		else if((s[2]==s[3]&&s[3]==s[4])||(s[3]==s[4]&&s[4]==s[5]))
			ans+=1000;
	}
	cout<<ans<<endl;
}
