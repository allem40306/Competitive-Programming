#include <bits/stdc++.h>
using namespace std;
#define N 105
int ans[N],lens;
bool b[N];
string s;
int main(){
	cin.tie(NULL);
	cin>>s;
	lens=s.size();
	memset(ans,-1,sizeof(ans));
	memset(b,0,sizeof(b));
	for(int i=1,j=1;i<=lens;i++){
		if(s[i-1]=='<'&&j<i&&!b[j]){
			b[j]=1;
			ans[i]=j;
			j++;
		}
	}
	for(int i=lens,j=lens;i;i--){
		if(s[i-1]=='>'&&j>i&&!b[j]){
			b[j]=1;
			ans[i]=j;
			j--;
		}
	}
	for(int i=1;i<=lens;i++){
		if(ans[i]==-1){	
			cout<<"Impossible\n";
			return 0;
		}
	}
	cout<<"Possible\n";
	for(int i=1;i<=lens;i++){
		if(i-1)cout<<' ';
		cout<<ans[i];
	}
	cout<<'\n';
}
