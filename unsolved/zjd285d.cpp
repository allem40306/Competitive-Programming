#include <bits\stdc++.h>
using namespace std;
int main(){
	int t,ti=0,chi;
	char ch[100],ca,cb;
	string s;
	stack<char> sa,sb;
	for(cin>>t;ti<t;ti++){
		getline(cin,s);
		getline(cin,s);
		chi=0;
		while(getline(cin,s),s!=""){
			ch[chi++]=s[0];
		}
		s="";
		while(sa.size())sa.pop();
		while(sb.size())sb.pop();
		for(int i=0;i<chi;i++){
			if(isalnum(ch[i]))
				sb.push(ch[i]);
			else if(ch[i]=='+'||ch[i]=='-')
				sa.push(ch[i]);
			else if(ch[i]=='*'||ch[i]=='\\'){
				if(ch[i+1]=='(')
					sa.push(ch[i]);
				else if(s)
				else{
					cb=sb.top();sb.pop();
					ca=sb.top();sb.pop();
					s+=ca+cb+ch[i];
				}
			}
			else if(ch[i]=='(')
				sa.push(ch[i]);
			else if(ch[i]==')'){
				while(sa.top()!='('){
					cb=sb.top();sb.pop();
					ca=sb.top();sb.pop();
					s+=ca+cb+sa.top();
					sa.pop();
				}sa.pop();
				while(sa.size()&&(sa.top()=='*'||sa.top()=='\\')){
					cb=sb.top();sb.pop();
					ca=sb.top();sb.pop();
					s+=ca+cb+sa.top();
					sa.pop();
				}
			}
		cout<<sa.size()<<' '<<sb.size()<<'\n';
		}
		while(sa.size()&&sb.size()){
			cb=sb.top();sb.pop();
			ca=sb.top();sb.pop();
			s=s+ca+cb+sa.top();
			sa.pop();
		}
		cout<<s<<'\n';
	}
}
