#include <bits/stdc++.h>
using namespace std;
const int N=55;
string s[N],r;
int t,n,m,q;
int dx[8]={-1,0,1,-1,1,-1,0,1},dy[8]={-1,-1,-1,0,0,1,1,1};
bool ok(int x,int y){
    int xx,yy;
    bool b;
    for(int i=0;i<8;i++){
        b=1;
        for(int j=0;j<r.size();j++){
            xx=x+j*dx[i];
            yy=y+j*dy[i];
            if(xx<0||xx>=n||yy<0||yy>=m||s[xx][yy]!=r[j]){
                b=0;
                break;
            }
        }
        if(b)return true;
    }
    return false;
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
	bool o=0;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>s[i];
			for(int j=0;j<m;j++){
				s[i][j]=tolower(s[i][j]);
			}
		}
		if(o)cout<<'\n';
		o=1;
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
