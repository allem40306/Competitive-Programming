#include <bits/stdc++.h>
using namespace std;
int pr,ans;//point
array<int,8>p,aa,na;
array<int,26>loc;
bool head,adj[26][26];
void sh(int n,int len){
	if(len>ans)return;
	if(n==pr){
		if(len<=ans&&aa>na){
			aa=na;
			ans=len;
		}
		return;
	}
	int maxlen;
	for(int i=0;i<pr;i++){
		if(loc[p[i]]==-1){
			maxlen=0;
			for(int j=0;j<8;j++){
				if(loc[p[j]]!=-1&&(adj[p[i]][p[j]]||adj[p[j]][p[i]])){
					maxlen=max(maxlen,n-loc[p[j]]);
				}
			}
			loc[p[i]]=n;
			na[n]=p[i];
			sh(n+1,max(len,maxlen));
			loc[p[i]]=-1;
		}
	}
}
int main(){
	cin.tie(NULL);
	string s;
	char f;//father son
	while(getline(cin,s),s!="#"){
		memset(adj,0,sizeof(adj));
		p.fill(-1);
		head=0;
		pr=0;
		for(int i=0;i<s.size();i++){
			if(isalpha(s[i])){
				if(head){
					adj[f-'A'][s[i]-'A']=adj[s[i]-'A'][f-'A']=1;
				}else{
					f=s[i];
					head=1;
				}
				if(find(p.begin(),p.end(),s[i]-'A')==p.end()){
					p[pr++]=s[i]-'A';
				}
			}
			if(s[i]==';'){
				head=0;
			}
		}
		aa.fill(30);
		na.fill(30);
		loc.fill(-1);
		ans=1000;
		sh(0,0);//search
		for(int i=0;i<pr;i++){
			cout<<char(aa[i]+'A')<<' ';
		}
		cout<<"->"<<ans<<"\n";
	}
}