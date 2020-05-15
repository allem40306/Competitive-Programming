#include <bits/stdc++.h>
using namespace std;
const int N=200005;

int main(){
	int n,m,nn[N],mm[N];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>nn[i];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>mm[i];
	}
	sort(nn,nn+n);
	sort(mm,mm+m);
	int i,j,k;
	for(i=j=k=0;i<m;){
		while(mm[i]!=nn[j]&&j<n)j++;
		if(j>=n)break;
		i++; j++;
	}
	cout<<((i==m)?"YES\n":"NO\n");
}
