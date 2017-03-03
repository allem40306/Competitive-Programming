#include <bits/stdc++.h>
using namespace std;
#define N 100000
int n,m,i,s[N+5],cnt[N+5],ans,anst[N+5],lis[10*N+5];//count
struct Query{
	int i,l,r,ans,anst;
	bool operator<(Query &x){
		if(l!=x.l)return l<x.l;
		return r<x.r;
	}
}q[N*10+5];
void fdo(int x){
	memset(cnt,0,sizeof(cnt));
	memset(anst,0,sizeof(anst));
	ans=0;
	for(int i=q[x].l;i<=q[x].r;i++){
		cnt[s[i]]++;
		if(cnt[s[i]]>ans)ans=cnt[s[i]];
		anst[cnt[s[i]]]++;
		if(cnt[s[i]])anst[cnt[s[i]]-1]--;
	}
	q[x].ans=ans; q[x].anst=anst[ans];
	return;
}
void add(int y){
	cnt[s[y]]++;
	if(cnt[s[y]]>ans)ans=cnt[s[y]];
	anst[cnt[s[y]]]++;
	if(cnt[s[y]])anst[cnt[s[y]]-1]--;
	}
void sub(int y){
	cnt[s[y]]--;
	if(cnt[s[y]]+1==ans&&anst[cnt[s[y]]+1]==1)ans=cnt[s[y]];
	anst[cnt[s[y]]]++;
	anst[cnt[s[y]]+1]--;
}
void mo(){
	int i=0,j,mm=sqrt(m),tl,tr;
	for(;i<m;i+=mm){
		fdo(i);//first do
		tl=q[i].l; tr=q[i].r;
		for(j=1;j<mm&&i+j<m;j++){
			while(q[i+j].l>tl)sub(tl),++tl;
			while(q[i+j].r<tr)sub(tr),--tr;
			while(q[i+j].r>tr)add(++tr);
			q[i+j].ans=ans; q[i+j].anst=anst[ans];
		}
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>s[i];
	for(i=0;i<m;i++){
		q[i].i=i;
		cin>>q[i].l>>q[i].r;
	}
	sort(q,q+m);
	for(i=0;i<m;i++){
		lis[q[i].i]=i;
	}
	mo();
	for(i=0;i<m;i++)
		cout<<q[lis[i]].ans<<' '<<q[lis[i]].anst<<endl;
}
