#include <bits/stdc++.h>
using namespace std;
struct dic{
	int y;
	string s,s1;
	dic(int y,string s,string s1):
		y(y),s(s),s1(s1){}
	dic(){};
}d[1000];
string uni(string s){
	for(int i=0;i<s.size();i++){
		s[i]=tolower(s[i]);
	}
	return s; 
}
bool cmp(dic a,dic b){
	if(a.y!=b.y)
		return a.y<b.y;
	return a.s1<b.s1;
}
int main() {
//	freopen("c236_03.in","r",stdin);
//	freopen("c236_03.out","w",stdout);
	cin.tie(NULL);
	int t,n,y,di=0;
	string s,s1;
	map<string,int>dm;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>s>>y;
			s1=uni(s);
			if(dm.find(s1)!=dm.end()){
				if(d[dm[s1]].y>y){
					d[dm[s1]].y=y;
					d[dm[s1]].s=s;
				}
			}else{
				dm[s1]=di;
				d[di]=dic(y,s,s1);
				di++;
			} 
		}
	}
	sort(d,d+di,cmp);
	for(int i=0;i<di;i++){
		cout<<d[i].s<<'\n';
	}
}
