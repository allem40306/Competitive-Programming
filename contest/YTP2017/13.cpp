#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,t[10005],p;
	priority_queue<int>pq;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t[i];
		t[i]=t[i]/100*60+t[i]%100;
	}
	for(int i=0,j;i<n;){
		if(!pq.empty()&&pq.top()>=t[j-1]+90)pq.pop();
		for(j=i;j<=n;j++){
			if(j==n||j-i==7||t[j]-t[i]>30){
				pq.push(t[j-1]);
//				cout<<j-1<<'\n';
				i=j;
				break;
			}
		}
	}
	cout<<max(int(pq.size()-2),0)<<'\n';
}
