#include <bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;
	while(getline(cin,s1)){
		getline(cin,s2);
		sort(s1.begin(),s1.end());
		sort(s2.begin(),s2.end());
		for(int i=0,j=0;i<s1.size()&&j<s2.size();){
			if(s1[i]==s2[j]){
				cout<<s1[i];
				i++;
				j++;
			}else if(s1[i]<s2[j]){
				i++;
			}else{
				j++;
			}
		}
		cout<<'\n';
	}
}
