#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,ans=0;
	string s;
	cin>>n>>s;
	for(int i=0,j;i<n-2;){
		if(s[i]=='1'&&s[i+1]=='0'&&s[i+2]=='1'){
			for(j=i+2;j<n;j++){
				if(s[j]=='0')break;
				ans++;
			}
			i=j;
		}else{
			i++;
		}
	}
	cout<<ans<<'\n';
}
