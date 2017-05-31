#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    int i, l, r, b;
    while(cin>>s){
    	r=b=0;
        for(i=0; i<s.size(); i++){
        if(s[i]==s[i+1]&&s[i+1]=='R')
        r++;
        else if (s[i]==s[i+1]&&s[i+1]=='B')
        b++;
        }
        if(r!=0&&b!=0){
        	if(r%2!=0&&b%2!=0)
        	cout<<"Saved!\n";
        	else
        	cout<<"BOOOOOOOOM!\n";
		}
		if(r==0||b==0){
			if((r+b)%2!=0)
			cout<<"Saved!\n";
			else
			cout<<"BOOOOOOOOM!\n";
		}
    }
}
