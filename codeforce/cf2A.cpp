#include <bits/stdc++.h>
using namespace std;
int n,ni,p,ans;
string s,as;
map<string,int> ma;
map<string,int>::iterator it;
int main(){
	for(cin>>n;ni<n;ni++){
		cin>>p>>s;
		ma[p]=s;
	}
	for(it=ma.begin();it!=ma.end();it++){
		if(it->second>ans){
			ans=it->second;
			an=it->first;
		}
	}
	cout<<as<<endl;
} 
