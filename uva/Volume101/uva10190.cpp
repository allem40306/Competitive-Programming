#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL m,n;
	vector<LL>v;
	bool b;
	while(cin>>n>>m){
		v.clear();
		b=0;
		if(n<=1||m<=1)b=1;
		while(!b&&1){
			v.push_back(n);
			if(n%m)break;
			n/=m;
		}
		if(!b&&n==1){
			for(int i=0;i<v.size();i++){
				if(i)cout<<' ';
				cout<<v[i];
			}
			cout<<'\n';
		}else{
			cout<<"Boring!\n";
		}
	}
}