#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define N 100000
string s[N]; int n,i;

int main(){
	cin>>n;
	getline(cin,s[0]);
	for(i=0;i<n;i++)getline(cin,s[i]);
	sort(s,s+n);
	for(i=0;i<n;i++)cout<<s[i]<<endl;
}

