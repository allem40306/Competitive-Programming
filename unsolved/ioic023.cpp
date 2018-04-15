#include <bits/stdc++.h>
using namespace std;
#define N 100005
string s;
long long t,ti=0,n,q,l,r,d,a[N];
struct Node{
	long long tag,val;
	Node *lc,*rc;
	Node(){ tag=val=0; lc=rc=NULL;}
	void pull(){
		val=lc->val+rc->val;
	}
};
Node* bulid(long long L,long long R){
	Node *node=new Node();
	if(L==R){
		node->val=a[L];
		return node;
	}
	long long M=(L+R)>>1;
	node->lc=bulid(L,M);
	node->rc=bulid(M+1,R);
	node->pull();
	return node;
}
void push(Node *node,long long L,long long R){
	if(!node->tag) return;
	if(L!=R){
		long long M=(L+R)>>1;
		node->lc->tag+=node->tag;
		node->rc->tag+=node->tag;
		node->lc->val+=node->tag*(M-L+1);
		node->rc->val+=node->tag*(R-M);
	}
	return;
}
void modify(Node* node,long long L,long long R,long long ql,long long qr,long long d){
	if(ql>R||qr<L)return;
	if(ql<=L&&qr>=R){
		node->tag+=d;
		node->val+=d*(R-L+1);
		return;
	}
	push(node,L,R);
	long long M=(L+R)>>1;
	modify(node->lc,L,M,ql,qr,d);
	modify(node->rc,M+1,R,ql,qr,d);
	node->pull();
	return;
}
long long query(Node *node,long long L,long long R,long long ql,long long qr){
	if(ql>R||qr<L)return 0;
	if(ql<=L&&qr>=R)return node->val;
	push(node,L,R);
	long long M=(L+R)>>1;
	return query(node->lc,L,M,ql,qr)+query(node->rc,M+1,R,ql,qr);
}
int main(){
	for(cin>>t;ti<t;ti++){
		cin>>n>>q;
		for(long long ni=1;ni<=n;ni++)
			cin>>a[ni];
			Node *root = bulid(1,n);
		for(long long qi=0;qi<q;qi++){
			cin>>s>>l>>r;
			if(s[0]=='a'){
				cin>>d;
				modify(root,1,n,l,r,d);
			}
			else
				cout<<query(root,1,n,l,r)<<endl;
		}
	}
}
