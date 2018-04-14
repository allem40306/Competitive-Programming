#include <bits/stdc++.h>
using namespace std;
int pai[5][10];
string s[15],x="TSW",y[10]={"DONG","NAN","XI","BEI","ZHONG","FA","BAI"};
map<string,int>ma;
map<char,int>mb;
void init(){
	for(int i=0;i<x.size();i++){
		mb[x[i]]=i+1;
	}
	for(int i=0;i<y.size();i++){
		ma[y[i]]=i+1;
	}
	memset(pai,0,sizeof(pai));
}
bool ok(){
	int p=0;
	for(int i=1;i<=7;i++){
		if(pai[4][i]==1)return 0;
		if(pai[4][i]==2)p++;
	}
	int a=0,b=0,c=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=7;j++){
			a=b; b=c;
			if(pai[i][j]){
				if(pai[i][j]/3){
					a+=3;
				}
				if((pai[i][j]-a>0)&&(pai[i][j+1]-b>0)&&(pai[i][j+2]-c)>0){
					b++; c++;
				}
				else if(pa)
			}
		}
	}
}
int main() {
	init();
	while(cin>>s[0]){
		if(s=="0")break;
		for(int i=1;i<13;i++)cin>>s[i];
		for(int i=0;i<13;i++){
			if(isalnum(s[i][0])){
				pai[s[i][0]-'0'][mb[s[i][1]]]++;
			}else{
				pai[4][ma[s[i]]]++;
			}
		}
		bool o=0;
		for(int i=1;i=3;i++){
			for(int j=1;j<=13;j++){
				pai[i][j]++;
				if(ok()){
					if(o)cout<<' ';
					o=1;
					cout<<i<<mb[j];
				}
				pai[i][j]--;
			}	
		}
		for(int i=4;i=4;i++){
			for(int j=1;j<=7;j++){
				if
				pai[i][j]++;
				if(ok()){
					if(o)cout<<' ';
					o=1;
					cout<<ma[j];
				}
				pai[i][j]--;
			}	
		}
		cout<<'\n';
	}
}
