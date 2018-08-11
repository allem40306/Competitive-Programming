#include <bits/stdc++.h>
using namespace std;


void turn(int &x,int &y){
	int tmp=7-x;
	x=y;
	y=tmp;
	return;
}

int main(){
	int n,st;//state
	string s;
	while(cin>>n,n){
		int top=1,north=2,west=4;
		while(n--){
			cin>>s;
			if(s[0]=='e')turn(west,top);
			else if(s[0]=='w')turn(top,west);
			else if(s[0]=='s')turn(top,north);
			else turn(north,top);
		}
		cout<<top<<'\n';
	}
}