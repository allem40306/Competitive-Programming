#include <iostream>
#include <string>
using namespace std;
#define gor(a,b,c) for(a=b;a<c;a++)
#define nts(x) (x=='0'?0:1)
#define N 55

int main() {
	int m,n;
	string s;
	while(cin>>m>>n){
		int i,j;
		string s[N];
		int co[N][N];
		gor(i,0,m)cin>>s[i];
		gor(i,0,m)
			gor(j,0,m)
				co[i][j]=nts(s[i][j]);
		
	}
}
