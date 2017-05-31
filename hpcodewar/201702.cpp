#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(NULL);
	int a[51]={1,1},n;
	for(int i=2;i<=50;i++)a[i]=a[i-1]+a[i-2];
	cin>>n;
	cout<<a[n];
}
