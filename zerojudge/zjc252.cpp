#include <iostream>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
int n,m;
bool b[20],vis[105][105];
string s[105];
struct loc{
	int x,y;
	loc(int x,int y):x(x),y(y){}
	loc(){};
}; 
stack<loc>st;
int px[8]={-1,0,1,-1,1,-1,0,1},py[8]={-1,-1,-1,0,0,1,1,1};
loc t;
bool dfs(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
//			cout<<i<<' '<<j<<'\n';
			if(!vis[i][j]&&(s[i][j]-'0')){
				if(!vis[i][j]&&b[s[i][j]-'0']){
				cout<<i<<' '<<j<<'\n';	
				return 0;
				}
				b[s[i][j]-'0']=1;
				st.push(loc(i,j));
				while(!st.empty()){
					t=st.top(); st.pop();
					vis[t.x][t.y]=1;
//					cout<<t.x<<' '<<t.y<<'\n';
					for(int k=0;k<8;k++){
						if(0<=i+px[k]&&i+px[k]<n&&0<=j+py[k]&&j+py[k]<m&&s[i+px[k]][j+py[k]]==s[t.x][t.y]&&!vis[i+px[k]][j+py[k]]){
							st.push(loc(i+px[k],j+py[k]));
						}
					}
				}
			}
		}
	}
	return 1;
}

int main(){
	while(cin>>n>>m,n||m){
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
		while(!st.empty())st.pop();
		for(int i=0;i<n;i++){
			cin>>s[i];
		}
		if(dfs()){
			cout<<"peace\n";
		}else{
			cout<<"choas\n";
		}
	}
}
