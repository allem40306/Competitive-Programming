#include <bits/stdc++.h>
using namespace std;
#define N 100
int n,m,i,j,ans,a[N];
string s[N];
int main(){
	for(cin>>n>>m;i<n;i++)
		cin>>s[i];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(isdigit(s[j][i]))
				if(a[j]&1==0)a[j]+=1;
			else if(isalpha(s[j][i]))
				if(a[j]&3==0)a[j]+=3;
			else if(a[j]&==0)a[]
		}
	}
}
