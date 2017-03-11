#include <iostream>
using namespace std;
struct Node{
	int v;
	Node *lc,*rc;
	Node():lc(NULL),rc(NULL){}
};
Node* ins(Node* h,int x){         
	if(!h){
		h=new Node();
		h->v=x;
		return h;
	}
	if(h->v>x)
		h->lc=ins(h->lc,x);
	else
		h->rc=ins(h->rc,x);
	return h;
}
void dfs(Node* h){
	if(!h)return;
	dfs(h->lc);
	dfs(h->rc);
	cout<<h->v<<endl;
}
int n,x;
string s;
int main(){
	Node *h=NULL;
	while(cin>>n)
		h=ins(h,n);
	dfs(h);
}
