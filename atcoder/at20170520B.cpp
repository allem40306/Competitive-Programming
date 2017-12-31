#include <bits/stdc++.h>
using namespace std;
#define N 105
int main(){
	int h,w;
	string s;
	cin>>h>>w;
	for(int i=0;i<w+2;i++)cout<<'#';
	cout<<'\n';
	for(int i=0;i<h;i++){
		cin>>s;
		cout<<'#'<<s<<'#'<<'\n';
	}
	for(int i=0;i<w+2;i++)cout<<'#';
	cout<<'\n';
}
