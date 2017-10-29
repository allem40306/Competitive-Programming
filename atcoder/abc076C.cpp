#include<bits/stdc++.h>
using namespace std;
string s,r;

int ok(int p){
	for(int i=0;i<r.size();i++){
		if(s[p+i]!='?'&&s[p+i]!=r[i])return 0;
	}
	return 1;
}

int main(){
	int c=0;
	bool b=0;
	cin>>s>>r;
	for(int i=s.size()-r.size();i>=0;i--){
		if(ok(i)){
			for(int j=0;j<r.size();j++){
				s[i+j]=r[j];
			}
			b=1;
			break;
		}
	}
	if(b){
		for(int i=0;i<s.size();i++){
			cout<<(s[i]=='?'?'a':s[i]);
		}
		cout<<'\n';
	}else{
		cout<<"UNRESTORABLE\n";
	}
} 
