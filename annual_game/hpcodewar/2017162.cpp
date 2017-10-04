#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	cin>>s;
	bool b[514];//tmt514
	int len=s.size();
	for(int i=0;i<len;i++)
		b[i]=(s[i]==s[0]);
	for(int i=0;i+1<len;i++){
		if(!b[i]){
			b[i]=!b[i];
			b[i+1]=!b[i+1];
		}
	}
	cout<<(b[len-1]?"Saved!\n":"BOOOOOOOOM!\n");
}
