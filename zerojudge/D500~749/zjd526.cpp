#include <iostream>
using namespace std;
struct Node{
	int v,lc,rc;
}node[1005];
void init(){
	for(int i=0;i<1005;i++){
		node[i].v=node[i].lc=node[i].rc=-1;
	}
}
int n,a,ni=0,ci;
bool go;
void gogo(int i){
	if(i)cout<<' ';
	cout<<node[i].v;
	if(node[i].lc!=-1){
		gogo(node[i].lc);
	}
	if(node[i].rc!=-1){
		gogo(node[i].rc);
	}
}
int main() {
	while(cin>>n){
		init();
		cin>>node[0].v;
		for(ni=1;ni<n;){
			cin>>node[++ni].v;
			ci=0;
			go=1;
			while(go){
				if(node[ni].v<node[ci].v){
					if(node[ci].lc==-1){
						node[ci].lc=ni;
						go=0;
					}
					ci=node[ci].lc;
				}else{
					if(node[ci].rc==-1){
						node[ci].rc=ni;
						go=0;
					}
					ci=node[ci].rc;
				}
			}
		}
		gogo(0);
		cout<<'\n';
	}
}