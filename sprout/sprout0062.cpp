#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define N 10
string s;
int a[N][N],r;
bool x[N][N],y[N][N],z[N][N];
bool init(){
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	memset(z,0,sizeof(z));
	for(int i=0;i<81;i++){
		if(s[i]=='.'){
			a[i/9][i%9]=0;
			r++;
		}else{
			a[i/9][i%9]=(s[i]-'0');
			if(x[i/9][a[i/9][i%9]]||y[i%9][a[i/9][i%9]]||z[i/9/3*3+i%9/3][a[i/9][i%9]])
				return 0;
			x[i/9][a[i/9][i%9]]=y[i%9][a[i/9][i%9]]=z[i/9/3*3+i%9/3][a[i/9][i%9]]=1;
		}
	}
	return 1;
}
bool dfs(int s,int r){
	if(!r)return 1;
	for(;s<81;s++){ 
		if(!a[s/9][s%9]){
			for(int i=1;i<=9;i++){
				if(!x[s/9][i]&&!y[s%9][i]&&!z[s/9/3*3+s%9/3][i]){
//					cout<<s/9<<' '<<s%9<<' '<<s/9/3*3+s%9/3<<' '<<i<<'\n';
					a[s/9][s%9]=i;
					x[s/9][i]=y[s%9][i]=z[s/9/3*3+s%9/3][i]=1;
					if(dfs(s+1,r-1))return 1;
					a[s/9][s%9]=0;
					x[s/9][i]=y[s%9][i]=z[s/9/3*3+s%9/3][i]=0;
				}
			}	
			return 0;
		}
	}
}
int main(){
//	freopen("owo.txt","w",stdout);
	while(cin>>s,s!="end"){
		if(init()&&dfs(0,r)){
			for(int i=0;i<9;i++){
				for(int j=0;j<9;j++){
					cout<<a[i][j];
				}
			}
			cout<<endl;
		}else{
			cout<<"No solution.\n";
		}
	}
}
