#include <bits/stdc++.h>
using namespace std;
#define N 100005

int main(){
	string a,b;
	cin>>a>>b;
	int sa=a.size(),sb=b.size();
	if(a!=b)cout<<max(sa,sb)<<endl;
	else cout<<-1<<endl;
}
