#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string s,t;
	cin>>s>>t;
	int a=s.size(),b=t.size();
	sort(s.begin(),s.end());
	sort(t.begin(),t.end()); 
	if(s==t)printf("Yes\n");
	else printf("No\n");
}
