#include <iostream>
using namespace std;
long long t,n,ti;
string ans;
bool ddd(long long x,string s){
//	cout<<x<<' '<<s<<'\n';
	if(x==n){
		ans=s;
		return 1;
	}
	if(x>n||n%x){
		return 0;
	}
	for(int i=9;i>1;i--){
		if(ddd(x*i,s+char(i+'0')))return 1;
	}
	return 0;
}
int main(){
	cin.tie(NULL);
	for(cin>>t;ti<t;ti++){
		cin>>n;
		ans="";
		if(n<10)cout<<n<<'\n';
		else{
			ddd(1,"");
			if(ans!=""){
				for(int i=ans.size();i;i--)
					cout<<ans[i-1];
				cout<<'\n';
			}
			else cout<<-1<<'\n';
		}
	}
}
