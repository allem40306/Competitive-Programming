#include <bits/stdc++.h>
using namespace std;
string s1,s2;
char ch;
int len1,len2,len,go,ans,sr;

void pplus(){
	ans=0;
	len1=s1.size(),len2=s2.size(),len=min(len1,len2);
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	go=0;
	for(int i=0;i<len;i++){
		if(s1[i]-'0'+s2[i]-'0'+go>=10){
			ans++;
			go=1;
		}else{
			go=0;
		}
	}
	if(len1!=len2&&go){
		if(len1>len2){
			for(int i=len;i<len1;i++){
				if(s1[i]!='9')break;
				ans++;
			}
		}else{
			for(int i=len;i<len2;i++){
				if(s2[i]!='9')break;
				ans++;
			}
		}
	}
}

void mminus(){
	ans=0;
	len1=s1.size(),len2=s2.size(),len=len1-len2;
	for(int i=len;i<len1;i++){
		if(s1[i]<s2[i-len]){
			sr=i-1;
			do{
				ans++;
			}while(s1[sr--]=='0');
			s1[i]='1';
		}else if(s1[i]==s2[i-len]){
			s1[i]='0';
		}
	}
}

int main(){
	cin.tie(NULL);
	int ti=1;
	while(cin>>s1>>ch>>s2){
//		cout<<"--"<<ti++<<'\n';
		if(ch=='+'){
			pplus();
		}else{
			mminus();
		}
		cout<<ans<<'\n';
	}
}
