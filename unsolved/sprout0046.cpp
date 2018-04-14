#include <iostream>
#include <cstring>
#include <string>
#include <queue> 
using namespace std;
#define N 20
#define M 1005
struct loc{
	int c,x,y,t;
	loc(int c,int x,int y,int t):c(c),x(x),y(y),t(t){}
}k=loc(0,0,0,0);
priority_queue<int> qa,qb;
int color[7]={1,3,4,5,6,8,18},a[M][M][N],aa,t,ti,n,x,y;
char ch;
bool uc[N],ua[N][N];//uc the number that resepent color 
queue<loc>q;
string s=".R.YOBP.G.........D.";
int f(char ch){for(int i=1;i<N-4;i++)if(ch==s[i])return i;}
void init(){
	memset(uc,0,sizeof(uc));
	memset(ua,0,sizeof(ua));
	for(int i=0;i<7;i++)uc[color[i]]=1;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<M;k++){
				a[i][j][k]=-1;
			}
		}
	}
	cin>>n;
	for(int i=0;i<3;i++){
		cin>>ch>>x>>y;
		q.push(loc(f(ch),x,y,0));
	}
	cin>>ch; aa=f(ch);
	while(qa.size())qa.pop();
	while(qb.size())qb.pop();
}
int main(){
	int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1},kx,ky;
	cin.tie(NULL);
	for(cin>>t,ti=0;ti<t;ti++){
		init();
		while(q.size()){
			k=q.front(),q.pop();
//			cout<<k.x<<' '<<k.y<<' '<<k.c<<' '<<k.t<<'\n';
			for(int i=0;i<8;i++){
				kx=k.x+dx[i],ky=k.y+dy[i];
				if(kx<0||kx>=n||ky<0||ky>=n)continue;
//				cout<<"111\n";
				for(int j=0;j<7;j++){
					if(a[kx][ky][color[j]]!=-1&&uc[color[j]+k.c]&&a[kx][ky][color[j]+k.c]==-1){
						a[kx][ky][color[j]+k.c]=k.t+1;
						cout<<color[j]<<' '<<k.c<<' '<<a[kx][ky][color[j]]<<' '<<a[kx][ky][color[j]+k.c]<<'\n';
						q.push(loc(color[j]+k.c,kx,ky,k.t+1));
						if(color[j]==aa)qb.push(k.t+1);
						else if(color[j]+k.c==aa)qa.push(k.t+1);
					}
				}
				if(a[kx][ky][k.c]==-1){
					a[kx][ky][color[k.c]]=k.t+1;
					q.push(loc(k.c,kx,ky,t+1));
					if(color[k.c]==aa)qb.push(t+1);
				}
			}
		}
//		cout<<qa.size()<<' '<<qb.size()<<'\n';
		int ans=0,cans=0;
		for(;qa.size();){
			if(!qb.size()||qa.top()<=qb.top()){
				cans++;
				qa.pop();
				ans=max(ans,cans);
			}else{
				cans--;
				qb.pop();
			}
		}
		cout<<ans<<'\n';
	}
}
