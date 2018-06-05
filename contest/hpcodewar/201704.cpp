#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	bool b=1;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1])b=0;
	}
	cout<<(b?"True\n":"False\n");
}
