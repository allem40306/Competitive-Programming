#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(string a,string b){
	if(a.size()!=b.size())
		return a.size()>b.size();
	int lens=a.size();
	for(int i=0;i<lens;i++)
		if(a[i]!=b[i])
			return a[i]>b[i];
}

int main(){
	int n,ni=0;
	string s[3];
	for(cin>>n;ni<n;ni++){
		cin>>s[0]>>s[1]>>s[2];
		sort(s,s+3,cmp);
		cout<<s[0]<<endl;
	}
}