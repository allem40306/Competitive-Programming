#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,aa;
	bool b=1;
	cin>>a;
	if(a>31)b=0;
	for(int i=0;i<6;i++){
		cin>>aa;
		if((aa==a+1||(aa==1&&a>27&&a<32))&&aa<=31);
		else b=0;
//		cout<<a<<aa<<'\n';
		a=aa;
	}
	cout<<(b?"Possible\n": "Impossible\n");
}
