#include <bits/stdc++.h>
using namespace std;
#define N 105
int main(){
	string s;
	cin>>s;
	char ch='a';
	int lens=s.size();
	bool b=1;
	for(int i=0;i<lens&&b;i++){
		if(s[i]>ch)b=0;
		else if(s[i]==ch)ch=ch+1;
	}
	if(b)cout<<"YES\n";
	else cout<<"NO\n";
}
