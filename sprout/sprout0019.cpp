#include <iostream>
#include <stack>
using namespace std;

int main(){
	int n,ni=0,s[100005],t,ti=0;
	for (cin >> t;ti<t;ti++){
		stack <int> ss;
		cin>>n;
		for(ni=0;ni<n;ni++)
			cin>>s[ni];	
		int a = 1, b = 0, ok = 1;	
		while (b < n){
			if (a == s[b]){ a++, b++; }
			else if (!ss.empty()&&ss.top() == s[b]){ ss.pop(); b++; }
			else if (a <= n)ss.push(a++);
			else { ok = 0; break; }
		}
		cout << ((ok) ? "Yes\n" : "No\n");
	}
}
