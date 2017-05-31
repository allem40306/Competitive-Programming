#include <iostream>
#include <cmath>
using namespace std;
const long long N=1000005;
int q,n,arr[N];
struct Node{
	long long add,ma;
	Node *lc,*rc;
	Node():add(0),ma(0),lc(NULL),rc(NULL){}
	void pull(){
		ma=max(lc->ma+lc->add,rc->ma+rc->add);
	}
};
void push(Node* node,int L,int R){
	if(!node->add)return;
	if(L!=R){
		int M=(L+R)>>1;
		node->lc->add+=node->add;
		node->rc->add+=node->add;
	}
	node->add=0;
	return;
}
Node* bulid(long long L,long long R){
	Node *node=new Node();
	if(L==R){
		node->ma=arr[L];
		return node;
	}
	long long M=(L+R)>>1;
	node->lc=bulid(L,M);
	node->rc=bulid(M+1,R);
	node->pull();
	return node;
}
Node* modify(Node* node,long long L,long long R,long long ql,long long qr,long long v){
	if(qr<L||ql>R)return node;
	if(ql<=L&&R<=qr){
		node->add+=v;
		if(L==R){
			node->ma+=node->add;
			node->add=0;
		}
		return node;
	}
	long long M=(L+R)>>1;
	push(node,L,R);
	modify(node->lc,L,M,ql,qr,v);
	modify(node->rc,M+1,R,ql,qr,v);
	node->pull();
//	cout<<L<<' '<<R<<' '<<node->add<<' '<<node->ma<<'\n';
	return node;
}
long long query(Node* node,long long L,long long R,long long ql,long long qr){
	if(qr<L||ql>R)return -1;
	if(ql<=L&&R<=qr)return node->ma+node->add;
	long long M=(L+R)>>1;
	push(node,L,R);
	node->pull();
	return max(query(node->lc,L,M,ql,qr),query(node->rc,M+1,R,ql,qr))+node->add;
}
int main(){
	cin.tie(NULL);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	Node* root=bulid(1,n);
	long long t,l,r,x;
	for(int i=0;i<q;i++){
		cin>>t;
		if(t%2){
			cin>>l>>r>>x;
			root=modify(root,1,n,l,r,x);
		}else{
			cin>>l>>r;
			cout<<query(root,1,n,l,r)<<'\n';
		}
	}
}
