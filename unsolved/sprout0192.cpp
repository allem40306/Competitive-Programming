#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
#define N 100005
int main(){
	int n,ni=0,s[100005],ss[100005],t,ti=0,sst;
	for (cin >> t;ti<t;ti++){
		memset(ss,0,sizeof(ss));
		sst=0;
		cin>>n;
		for(ni=0;ni<n;ni++)
			cin>>s[ni];	
		int a=1,b=0,ok=1;	
		while (b < n){
			if (a == s[b]){ a++, b++; }
			else if (sst&&ss[sst] == s[b]){ sst--; b++; }
			else if (a <= n){ss[sst]=a++;sst++;}
			else { ok = 0; break; }
		}
		cout << ((ok) ? "Yes\n" : "No\n");
	}
}
