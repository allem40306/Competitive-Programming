#include <iostream>
#include <cmath>
using namespace std;
const long long N=1000005;
int t,ti=0,n,arr[N];
struct Node{
	long long val,mi;
	Node *lc,*rc;
	Node():val(0),mi(0),lc(NULL),rc(NULL){}
	void pull(){
		val=lc->val+rc->val;
		mi=min(lc->mi,rc->mi);
	}
};
Node* bulid(long long L,long long R){
	Node *node=new Node();
	if(L==R){
		node->val=node->mi=arr[L];
		return node;
	}
	long long M=(L+R)>>1;
	node->lc=bulid(L,M);
	node->rc=bulid(M+1,R);
	node->pull();
	return node;
}
Node* modify(Node* node,long long L,long long R,long long q,long long v){
	if(q<L||q>R)return node;
	if(L==R){
		node->val=node->mi=v;
		return node;
	}
	long long M=(L+R)>>1;
	modify(node->lc,L,M,q,v);
	modify(node->rc,M+1,R,q,v);
	node->pull();
	return node;
}
long long query(Node* node,long long L,long long R,long long ql,long long qr){
	if(qr<L||ql>R)return N;
	if(ql<=L&&R<=qr)return node->mi;
	long long M=(L+R)>>1;
//	cout<<L<<' '<<M<<' '<<R<<'\n';
	return min(query(node->lc,L,M,ql,qr),query(node->rc,M+1,R,ql,qr));
}
int main(){
	cin.tie(NULL);
	cin>>t>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	Node* root=bulid(1,n);
	long long q,x,y;
	for(int i=0;i<t;i++){
		cin>>q>>x>>y;
		if(q%2){
			cout<<query(root,1,n,x+1,y+1)<<'\n';
		}else{
			root=modify(root,1,n,x+1,y);
		}
	}
}
