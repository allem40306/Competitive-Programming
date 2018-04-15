#include <iostream>
#include <string>
using namespace std;

string its(int i){string r;while(i){r=char(i%10+'0')+r;i/=10;}return r;}

int main(){
	int n,c=1;string s,r;
	cin>>n>>s;
	char ch=s[0];
	for(int i=1;i<n;i++){
		if(s[i]!=ch){
			r+=its(c)+ch;
			ch=s[i];c=1;
		}else c++;
	}r+=its(c)+ch;
	cout<<(r.size()<n?r:s)<<endl;
}