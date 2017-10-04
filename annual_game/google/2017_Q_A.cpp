#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(NULL);
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t,i=1,lens,k,ans;
	string s;
	bool ok;
	bool b[1000];
	for(cin>>t;i<=t;i++){
		cin>>s>>k;
		lens=s.size();
		ans=0;
		ok=1;
		for(int i=0;i<lens;i++)
			b[i]=(s[i]=='+');
		for(int j=0,jj;j+k<=lens;j++){
			if(!b[j]){
				ans++;
				for(jj=0;jj<k;jj++)
					b[j+jj]=!b[j+jj];
			}
		}
		for(int i=0;i<lens;i++){
			if(!b[i])ok=0;
		}
		cout<<"Case #"<<i<<": ";
		if(ok)cout<<ans<<'\n';
		else cout<<"IMPOSSIBLE\n";
	}
}
