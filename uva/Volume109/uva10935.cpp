#include <bits/stdc++.h>
using namespace std;
const int N=100;

void del(int* next,int* last,int &s){
	int L=last[s],R=next[s];
	next[L]=R;
	last[R]=L;
	cout<<' '<<s;
	s=next[s];
}

int main(){
	int n,next[N],last[N];
	while(cin>>n,n){
		int s=1;
		for(int i=1;i<=n;i++){
			next[i]=i+1;
			last[i]=i-1;
		}
		last[1]=n;
		next[n]=1;
		s=1;
		cout<<"Discarded cards:";
		for(int i=0;i<n-1;i++){
			if(i)cout<<',';
			del(next,last,s);
			s=next[s];
		}
		cout<<"\nRemaining card: "<<s<<'\n';
	}
}
