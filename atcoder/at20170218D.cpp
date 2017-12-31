#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n;
string s;
bool b[N],bb[N];
bool f(int i,int j){
	bb[0]=i;bb[1]=j;
	for(int k=2;k<n;k++){
		if(b[k-1]!=bb[k-1])
			bb[k]=1-bb[k-2];
		else
			bb[k]=bb[k-2];
	}
	if(bb[n-1]==bb[1]&&(bb[0]!=b[0]))return 0;
	if(bb[n-1]!=bb[1]&&(bb[0]==b[0]))return 0;
	if(bb[n-2]==bb[0]&&(bb[n-1]!=b[n-1]))return 0;
	if(bb[n-2]!=bb[0]&&(bb[n-1]==b[n-1]))return 0;
	return 1;
}
bool solve(){
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			if(f(i,j))return 1;
		}
	}
	return 0;
}
int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='o')b[i]=1;
		else b[i]=0;
	}
	if(solve()==0)cout<<"-1\n";
	else for(int i=0;i<n;i++){
		if(bb[i])cout<<'S';
		else cout<<'W';
	}
	cout<<'\n';
}
