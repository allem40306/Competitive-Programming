#include <iostream>
#include <algorithm>
#define N 105
using namespace std;
struct loc{
	int x,y;
};
bool cmp(loc a,loc b){
	if(a.x!=b.x)
	return a.x>=b.x;
	return a.y>=b.y; 
}
int main(){
	int n;
	loc arr[N];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>arr[i].x;
	for(int i=0;i<n;i++)
		cin>>arr[i].y;
	sort(arr,arr+n,cmp);
	int ans=0,nx=0,ny=0;
	for(int i=0;i<n;i++){
		if(arr[i].x>nx||arr[i].y>ny){
			cout<<arr[i].x<<' '<<arr[i].y<<'\n';
			ans++;
			nx=max(arr[i].x,nx);
			ny=max(arr[i].y,ny);
		}
	}
	cout<<(ans%2?"A\n":"B\n");
}
