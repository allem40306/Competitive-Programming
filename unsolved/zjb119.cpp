#include <bits/stdc++.h>
using namespace std;

int main(){
	double s,t,in,ti[5]={0.7,0.8,0.9,1.0};
	int p[5],x,m,n;
	while(cin>>s>>t>>n){
		in=x=0;
		while(n--){
			cin>>m;
			x+=m;
		}
		p[0]=ceil(t*0.2);
		p[1]=ceil(t*0.4)-p[0];
		p[2]=ceil(t*0.6)-p[0]-p[1];
		p[3]=t-p[0]-p[1]-p[2];
		for(int i=0;i<4;i++){
			if(x<=0)break;
			in+=min(p[i],x)*ti[i]*s;
			x-=p[i];
		}
		printf("%.0f\n",in-s*t*0.3);
	}
} 
