#include <iostream>
#include <string>
using namespace std;
int a[26] = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4 };
int main(){
	int ans, t, ti = 1, i,j; string s;
	for (cin >> t >> ws; ti <= t; ti++){
		ans = 0;
		getline(cin, s);
		for(i=0,j=s.size();i<j;i++)
			s[i]==' '?ans+=1:ans+=a[s[i]-'a'];
			printf("Case #%d: %d\n", ti, ans);
	}
}
