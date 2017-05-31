#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 105
int bi=0,b[N],ip;
char ch;
struct loc{
	int i,b[N],ip;
};
loc tmt[3];
int c(){
	int ans=0;
	for(int i=0;i<=bi;i++){
		for(int j=i+1;j<=bi;j++){
			if(b[i]>b[j])ans++;
		}
	}
	return ans;
}
int c2(int a){
	int ans=0;
	for(int i=0;i<=bi;i++){
		for(int j=i+1;j<=bi;j++){
			if(tmt[a].b[i]>tmt[a].b[j])ans++;
		}
	}
	return ans;
}
bool cmp(loc a,loc b){
	if(a.ip!=b.ip)
		return a.ip<b.ip;
	return a.i<b.i;
}
int main(){
	while(cin>>b[bi]>>ch){
		if(ch==';')break;
		bi++;
	}
	ip=c();
	for(int i=0;i<=2;i++){
		for(int j=0;j<=bi;j++){
			cin>>tmt[i].b[j];
			if(j!=bi)cin>>ch;
		}
		tmt[i].i=i;
		tmt[i].ip=c2(i);
		tmt[i].ip=abs(tmt[i].ip-ip); 
		if(i!=2)cin>>ch;
	}
	sort(tmt,tmt+3,cmp);
	for(int i=0;i<3;i++){
		cout<<char('A'+tmt[i].i);
	}
	cout<<'\n';
}
