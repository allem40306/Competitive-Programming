#include <iostream>
#include <string>
using namespace std;
#define N 1005
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};

struct lo{
	int x,y;
	loc(int x,int y){x=0;y=0;}
};
lo j[N],f[N];
int r,c;
void ff(char ch,string *s){
	int p=0;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		 	if(s[i][j]==ch)j[p++]=loc(i,j);
	return;
}

int main(){
	int t,i=0;
	for(cin>>t;i<t;t++){
		cin>>r>>c;
		string s[M];
		for(int j=0;j<n;j++)vin>>s[j];
		ff('i',&s); ff('j',&s);
	}
}
