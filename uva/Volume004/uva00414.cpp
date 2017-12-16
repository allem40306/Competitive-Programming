#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,sum,maxx,x;
	string s;
	while(cin>>n,n){
		sum=maxx=0;
		cin>>ws;
		for(int i=0;i<n;i++){
			getline(cin,s);
			x=0;
			for(int j=0;j<s.size();j++){
				x+=(s[j]=='X');
			}
			sum+=x;	
			maxx=max(maxx,x);
		}
		cout<<maxx*n-sum<<'\n';
	}
}
