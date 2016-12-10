#include<iostream>
using namespace std;
int main() {
	int a, n, x;
	char s[11];
	cin>>n;
	while(n--) {
 	a = 0, x = 1;
		for(cin>>s; s[a]; a++)
			x *= s[a]-'0';
		cout<<x<<endl;
	}
	return 0;
}
