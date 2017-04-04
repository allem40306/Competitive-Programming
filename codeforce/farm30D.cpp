#include <bits/stdc++.h>
using namespace std;
#define N 1005
double zone(double x,double y){
	if(x==0)return x>=0?1.5:3.5;
	if(y==0)return y>=0?0:2.5;
	if(y>0)return x>0?1:2;
	return x>0?4:3;
}
struct loc{
	double x,y,z;
}a[N];
bool cmp(loc a,loc b){
	if(a.z!=b.z)return a.z<b.z;
	if(ceil(a.z)!=a.z)return 1;
	return a.y/a.x<b.y/b.x;
}
int main(){
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].z=zone(a[i].x,a[i].y);
	}
	sort(a,a+n,cmp);
//	for(int i=0;i<n;i++){
//		cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].z<<'\n';
//	}
	int s=0;
	for(int i=0;i<n;i++){
		if(a[i].x*a[(i+1)%n].x+a[i].y*a[(i+1)%n].y<=0){
			s=(i+1)%n;
			break;
		}
	}
	for(int i=0;i<n-1;i++){
		if(a[(s+i)%n].x*a[(s+i+1)%n].x+a[(s+i)%n].y*a[(s+i+1)%n].y<=0){
			cout<<"-1\n";
			return 0;
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[(s+i)%n].x<<' '<<a[(s+i)%n].y<<'\n';
	}
}
