#include <bits/stdc++.h>
using namespace std;
#define N 1005
int n,si,ri,i,ma,mi;
bool ss[N],rr[N];
string s,r;
int main(){
	cin>>n>>s>>r;
	sort(s.begin(),s.end());
	sort(r.begin(),r.end());
	for(ri=si=n-1,mi=n;ri>=0&&si>=0;){
		if(r[ri]>=s[si]){
			mi--;si--;ri--;
		}else{
			si--;
		}
	}
	for(ri=si=n-1;ri>=0&&si>=0;){
		if(r[ri]>s[si]){
			ma++;si--;ri--;
		}else{
			si--;
		}
	}
	cout<<mi<<endl<<ma<<endl;}
