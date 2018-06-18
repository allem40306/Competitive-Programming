#include <bits/stdc++.h>
using namespace std;
#define N 100
int vis[N][N], c[N], n, to,o=0;

void search(int cur){
	if (cur == n){
		to++;
		if(o)cout<<'\n';
		o=1;
		for (int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(c[i]==j){
                    cout<<'Q';
                }else{
                    cout<<'x';
                }
            }
            cout<<'\n';
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n]){
			c[cur] = i;
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
			search(cur + 1);
			vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
		}
	}
	return;
}

int main(){
    while(cin>>n,n){
        to=0;
        memset(c,0,sizeof(c));
        memset(vis,0,sizeof(vis));
        search(0);
		if(o)cout<<'\n';
		o=1;
		cout<<to<<'\n';
    }
}
