#include <iostream>
#include <string>
using namespace std;
#define N 1005
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};

struct loc{
	int x, y;
	loc(int x, int y) :x(x), y(y){}
}k = loc(0, 0);

stack <loc> j;

int r,c;
void ff(char ch,string *s){
	int p=0;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
		 	if(s[i][j]==ch)j.push()loc(i,j);
	return;
}

int main(){
	int t,i=0;
	for(cin>>t;i<t;t++){
		cin>>r>>c;
		string s[N];
		for(int j=0;j<r;j++)cin>>s[j];
		ff('i',s); ff('j',s);
	}
}
