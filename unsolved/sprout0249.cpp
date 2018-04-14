#include <iostream>
#include <cmath>
using namespace std;
const long long N=1000005;
const long long MAX = 10000000000000000;
long long t,ti=0,n,arr[N];
struct Node{
	long long mi,ma,ans;
	Node *lc,*rc;
	Node():mi(0),ma(0),ans(0),lc(NULL),rc(NULL){}
	void pull(){
		mi=min(lc->mi,rc->mi);
		ma=max(lc->ma,rc->ma);
		ans=max(max(lc->ans,rc->ans),rc->ma-lc->mi);
    }
};
Node* bulid(long long L,long long R){
	Node *node=new Node();
	if(L==R){
		node->mi=node->ma=arr[L];
		return node;
	}
	long long M=(L+R)>>1;
	node->lc=bulid(L,M);
	node->rc=bulid(M+1,R);
	node->pull();
	return node;
}
long long query_ma(Node* node,long long L,long long R,long long ql,long long qr){
    if(ql<=L&&R<=qr)return node->ma;
    long long M=(L+R>>1),ans=-MAX;
    if(ql<=M)ans=max(ans,query_ma(node->lc,L,M,ql,qr));
    if(qr>M)ans=max(ans,query_ma(node->rc,M+1,R,ql,qr));
    return ans;
}
long long query_mi(Node* node,long long L,long long R,long long ql,long long qr){
    if(ql<=L&&R<=qr)return node->mi;
    long long M=(L+R>>1),ans=MAX;
    if(ql<=M)ans=min(ans,query_mi(node->lc,L,M,ql,qr));
    if(qr>M)ans=min(ans,query_mi(node->rc,M+1,R,ql,qr));
    return ans;
}
long long query(Node* node,long long L,long long R,long long ql,long long qr){
//	cout<<L<<' '<<R<<' '<<ql<<' '<<qr<<'\n';
	if(ql<=L&&R<=qr)return node->ans;
	long long M=(L+R)>>1,ans=0;
	if(ql<=M) ans=max(ans,query(node->lc,L,M,ql,qr));
	if(qr>M) ans=max(ans,query(node->rc,M+1,R,ql,qr));
	if(ql<=M&&qr>M)ans=max(ans,query_ma(node->rc,M+1,R,M+1,qr)-query_mi(node->lc,L,M,ql,M));
	return ans;
}
int main(){
	cin.tie(NULL);
	cin>>n>>t;
	arr[0]=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	Node* root=bulid(0,n);
	long long x,y;
	for(int i=0;i<t;i++){
		cin>>x>>y;
		cout<<query(root,0,n,x-1,y)<<'\n';
	}
}
