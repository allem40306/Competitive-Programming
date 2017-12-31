#include <bits/stdc++.h>
using namespace std;
const int N=15;
int st[N],a,b,c,d,vis[4][4],vis2[4][4];// x,y,\,/ 
bool used[200000];

void print_state(){
	for(int i=0;i<9;i++){
		cout<<st[i];
//		if(i%3==2)cout<<'\n';
	}
	cout<<'\n';
}

int calid(){
	int val=0;
	for(int i=0;i<9;i++){
		val=val*3+st[i];
	}
	return val;
}

void sol(int r){
	int id=calid();
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(vis[i][j]==3){
				if(!used[id]){
					used[id]=1;
					a++; b++;
				}
				return;
			}
			if(vis2[i][j]==3){
				if(!used[id]){
					used[id]=1;
					a++; c++;
				}
				return;
			}
		}
	}
	if(!used[id]&&r==9){
		used[id]=1;
		a++;d++;
	}
	if(r%2){
		for(int i=0;i<9;i++){
			int x=i/3,y=i%3;
			if(!st[i]&&vis2[0][x]<3&&vis2[1][y]<3&&vis2[2][y-x+2]<3&&vis2[3][x+y]<3){
				vis2[0][x]++;vis2[1][y]++;vis2[2][y-x+2]++;vis2[3][x+y]++;st[i]=2;
				sol(r+1);
				vis2[0][x]--;vis2[1][y]--;vis2[2][y-x+2]--;vis2[3][x+y]--;st[i]=0;
			}
		}
	}else{
		for(int i=0;i<9;i++){
			int x=i/3,y=i%3;
			if(!st[i]&&vis[0][x]<3&&vis[1][y]<3&&vis[2][y-x+2]<3&&vis[3][x+y]<3){
				vis[0][x]++;vis[1][y]++;vis[2][y-x+2]++;vis[3][x+y]++;st[i]=1;
				sol(r+1);
				vis[0][x]--;vis[1][y]--;vis[2][y-x+2]--;vis[3][x+y]--;st[i]=0;
			}
		}
	}
	return;
}

int main(){
	string s;
	int x,y,no,nx;
	while(cin>>s){
		no=nx=0;
		memset(vis,0,sizeof(vis));
		memset(vis2,0,sizeof(vis2));
		memset(used,0,sizeof(used));
		memset(st,0,sizeof(st));
		for(int i=0;i<9;i++){
			x=i/3; y=i%3;
			if(s[i]=='-'){
				st[i]=0;
			}
			else if(s[i]=='O'){
				no++;
				st[i]=1;
				vis[0][x]++;vis[1][y]++;vis[2][y-x+2]++;vis[3][x+y]++;
			}
			else{
				nx++;
				st[i]=2;
				vis2[0][x]++;vis2[1][y]++;vis2[2][y-x+2]++;vis2[3][x+y]++;
			}
		}
		a=b=c=d=0;
		sol(no+nx); 
		cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
	}
}
