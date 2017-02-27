#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define N 100005
struct Node{
    int last,next;
    Node(){}
};
int main(){
	int n,m,x,y,z,t,pr=-1;
	Node c[N];
    cin>>n>>m;
    int h=1,e=n;
    for(int i=1;i<=n;i++){
    	c[i].last=i-1;
    	c[i].next=i+1;
	}
	for(int i=0;i<m;i++){
		cin>>x>>y;
		if(x%2){
			if(y==h)continue;
			z=c[y].last;
			c[c[z].last].next=y;
			c[c[y].next].last=z;
			c[y].last=c[z].last;
			c[z].next=c[y].next;
			c[y].next=z;
			c[z].last=y;
			if(z==h)h=y;
			if(y==e)e=z;
		}else{
			c[c[y].last].next=c[y].next;
			c[c[y].next].last=c[y].last;
			if(y==h)h=c[y].next;
			if(y==e)e=c[y].last;
		}
	}
	for(int i=h;i>0&&i<=n;i=c[i].next){
		if(i!=h)cout<<' ';
		cout<<i;
	}
	cout<<endl;
}
