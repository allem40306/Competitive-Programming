#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	string s1,s2;
	array<int,30>a1,a2;
	while(cin>>s1>>s2){
		a1.fill(0);
		a2.fill(0);
		for(int i=0;i<s1.size();i++){
			a1[s1[i]-'A']++;
			a2[s2[i]-'A']++;
		}
		sort(a1.begin(),a1.end());
		sort(a2.begin(),a2.end());
		cout<<(a1==a2?"YES\n":"NO\n");
	}
}
