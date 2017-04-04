#include <bits/stdc++.h>
using namespace std;
#define N 60005
#define M (L+R)>>1
double n,i,x[N],v[N];
bool che(double x){
	int mi=x[0]-t*v[0],
}
int main(){
	for(cin>>n;i<n;i++)
		cin>>x[i]>>v[i];
	double L=1,R=1e+9,ans;
	while(R-L<1e-7){
		if(che(M))
			L=M;
		else
			R=M;
	}
}
