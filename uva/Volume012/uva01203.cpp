#include <bits/stdc++.h>
using namespace std;

struct node{
	int id,t,nt;
	node(){};
	node(int id,int t,int nt):id(id),t(t),nt(nt){}
	bool operator <(const node&b)const{
		if(nt!=b.nt)return nt>b.nt;
		return id>b.id;
	}
};

int main(){
	string s;
	int a,b,k;
	priority_queue<node>pq;
	while(cin>>s){
		if(s=="#")break;
		cin>>a>>b;
		pq.push(node(a,b,b));
	}
	cin>>k;
	node x;
	while(k--){
		x=pq.top(); pq.pop();
		cout<<x.id<<'\n';
		x.nt+=x.t;
		pq.push(x);
	}
}
