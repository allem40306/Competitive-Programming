#include <bits/stdc++.h>
using namespace std;
int main(){
	int x,y,g[15]={0,1,3,1,2,1,2,1,1,2,1,2,1};
	cin>>x>>y;
	if(g[x]==g[y])cout<<"Yes\n";
	else cout<<"No\n";	
}
