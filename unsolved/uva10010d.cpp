#include <bits/stdc++.h>
using namespace std;
const int N=55;
string s[N],r;
int t,n,m,q;
int dx[8]={-1,0,1,-1,1,-1,0,1},dy[8]={-1,-1,-1,0,0,1,1,1};
bool ok(int i,int j){
	
}

void go(){
	for(int j=0;j<n;j++){
		for(int k=0;k<m;k++){
			if(ok(j,k)){
				cout<<j+1<<' '<<k+1<<'\n';
				return;
			}
		}
	}
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>s[i];
			for(int j=0;j<m;j++){
				s[i][j]=tolower(s[i][j]);
			}
		}
		cin>>q;
		for(int i=0;i<q;i++){
			cin>>r;
			for(int i=0;i<r.size();i++){
				r[i]=tolower(r[i]);
			}
			go();
		}
	}
}
