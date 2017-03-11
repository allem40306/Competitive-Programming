#include <iostream>
using namespace std;
#define N 10005
struct DQ{
	int a[N],L,R;
	void clear(){L=N; R=N-1;}
	void push_front(int x){a[--L]=x;}
	void pop_back(){R--;}
	void pop_front(){L++;}
	int front(int x){return a[L+x];}
	int back(int x){return a[R-x];}
	int size(){return R-L+1;}
}dq ;
int n,i=1,s,t[N],c[N],ts[N],cs[N],dp[N],j;
double fa(int x){return -ts[x];}
double fb(int x){return (double)ts[x]*cs[n]+dp[x+1];}
double fp(int x,int y){return ((fb(y)-fb(x))/(fa(x)-fa(y)));}
//fp two line get one point
int main(){
    for(cin>>n>>s;i<=n;i++){
        cin>>t[i]>>c[i];
        ts[i]=ts[i-1]+t[i];
        cs[i]=cs[i-1]+c[i];
    }
    dq.clear();dq.push_front(N+1);
    for(i=n;i;i--){
    	while(dq.size()>=2&&fp(i,dq.front(0))>=fp(dq.front(0),dq.front(1)))dq.pop_front();
    	dq.push_front(i);
    	while(dq.size()>=2&&fp(dq.back(1),dq.back(0))>=cs[i-1])dq.pop_back();
    	j=dq.back(0);
    	dp[i]=(s*cs[n]-s*cs[i-1]-ts[i-1]*cs[n]+ts[i-1]*cs[i-1])+(ts[j]*cs[n]+dp[j+1])-(ts[j]*cs[i-1]);
//    	cout<<dp[i]<<endl;
	}
	cout<<dp[1]<<endl;
}
