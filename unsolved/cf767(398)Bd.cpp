
 #include <bits/stdc++.h>
using namespace std;
#define N 1000005
long long n,ts,tf,t,a[N][2],ans=-1,anst,tt;
int main(){
	cin>>ts>>tf>>t>>n;
	for(long long i=0;i<n;i++)
		cin>>a[i][0];
	a[0][1]=max(a[0][0]+t-1,ts);
	for(long long i=1;i<n;i++){
		if(a[i][0]>a[i-1][1])
			a[i][1]=a[i][0]+t-1;
		else
			a[i][1]=a[i-1][1]+t;
	}
	anst=a[0][0]-1;
	if(a[0][0]<=ts&&tf-ts+1>=t){
		ans=ts-a[0][0]+1;
	}else{
		ans=0;
	}
	for(long long i=0;i<n&&tt<=tf&&ans!=0;i++){
		tt=a[i][0]-1;
		while(a[i][1]+t==a[i+1][1])i++;
		if(a[i][1]+t<=tf){
			anst=a[i][1]+1;
			break;
		}
		if(ans==-1||ans>a[i][1]+1-tt){
			ans=a[i][1]+1-tt;
			anst=tt;
		}
	}
	cout<<anst<<endl;
}
