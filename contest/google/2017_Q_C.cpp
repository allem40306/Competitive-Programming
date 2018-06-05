#include <bits\stdc++.h> 
using namespace std;
int main(){
	cin.tie(NULL);
	freopen("C-large-practice.in","r",stdin);
	freopen("C-large-practice.out","w",stdout);
	long long t,i=1,n,k,d,ans[2];
	map<long long,long long>ma;//distance,people
	pair<long long,long long>pa;
	for(cin>>t;i<=t;i++){
		cin>>n>>k;
		ma.clear();
		ma[n]=1;
		while(k){
			pa=*ma.rbegin();
			ma.erase(pa.first);
			if(pa.second>=k){
				ans[0]=pa.first/2;
				ans[1]=(pa.first-1)/2;
				break;
			}
			k-=pa.second;
			d=pa.first; 
			if(d%2){
				ma[d/2]+=2*pa.second;
			}else{
				ma[d/2]+=pa.second;
				ma[d/2-1]+=pa.second;
			}
		}
		cout<<"Case #"<<i<<": ";
		cout<<ans[0]<<' '<<ans[1]<<'\n';
	}
}
