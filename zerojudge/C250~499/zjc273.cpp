#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("c273_00.in","r",stdin);
	freopen("c273_00.out","w",stdout);
	int a,b;
	string s;
	bool c=0;
	while(cin>>s){
		c=1;
		a=b=0;
		for(int i=0;i<s.size();i++){
			if(i%2){
				b+=s[i]-'0';
			}else{
				a+=s[i]-'0';
			}
		}
		cout<<a-b<<'\n';
	}
	if(!c)cout<<"I finish the homework.\n";
} 
