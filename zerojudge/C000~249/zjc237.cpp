#include <bits/stdc++.h>
using namespace std;
const long long N=3000005;
int arr[N];
struct Node{
	long long v;
	Node *lc,*rc;
	Node():v(0),lc(NULL),rc(NULL){}
	void pull(){
		v=lc->v+rc->v;
	}
};
Node* bulid(long long L,long long R){
	Node *node=new Node();
	if(L==R){
		node->v=arr[L];
		return node;
	}
	long long M=(L+R)>>1;
	node->lc=bulid(L,M);
	node->rc=bulid(M+1,R);
	node->pull();
	return node;
}
void modify(Node* node,long long L,long long R,long long i,int d){
	if(L==R){
		node->v+=d;
		return;
	}
	long long M=(L+R)>>1;
	if(i<=M)modify(node->lc,L,M,i,d);
	else modify(node->rc,M+1,R,i,d);
	node->pull();
	return;
}
long long query(Node* node,long long L,long long R,long long ql,long long qr){
	if(qr<L||ql>R)return 0;
	if(ql<=L&&R<=qr)return node->v;
	long long M=(L+R)>>1;
	return query(node->lc,L,M,ql,qr)+query(node->rc,M+1,R,ql,qr);
}
int main(){
	cin.tie(NULL);
	int m,q,am[300000][2],aq[300000][3],x,y;
	vector<int>vm[30],vq[30];
	for(int i=1;i<=18;i++){
		cin>>arr[i];
	}
	Node* node=bulid(1,18);
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>am[i][0]>>x>>am[i][1]>>y;
		if(y==1)am[i][1]*=-1;
		vm[x].push_back(i);
	}
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>aq[i][0]>>aq[i][1]>>x;
		vq[x].push_back(i);
	}
	for(int i=1;i<=24;i++){
		for(int j=0;j<vm[i].size();j++){
			modify(node,1,18,am[vm[i][j]][0],am[vm[i][j]][1]);
		}
		for(int j=0;j<vq[i].size();j++){
			aq[vq[i][j]][2]=query(node,1,18,aq[vq[i][j]][0],aq[vq[i][j]][1]);
		}
	}
	for(int i=0;i<q;i++){
		cout<<aq[i][2]<<'\n';
	}
}
