#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int ti=1;ti<=t;ti++){
		int M=0,J=0,n,v;
		cin>>n;
		while(n--){
			cin>>v;
			M+=v/30*10+10;
			J+=v/60*15+15;
		}
		if(M<J){
			cout<<"Case "<<ti<<": Mile "<<M<<'\n';
		}else if(M>J){
			cout<<"Case "<<ti<<": Juice "<<J<<'\n';
		}else {
			cout<<"Case "<<ti<<": Mile Juice "<<M<<'\n';
		}
	}
}