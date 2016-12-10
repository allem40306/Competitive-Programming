#include <iostream>
#include <string>
using namespace std;
int a[26] = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4 };
int main(){
	int ans, t, ti = 1, i; string s;
	for (cin >> t >> ws; ti <= t; ti++){
		ans = 0;
		getline(cin, s);
		for(i=s.size()-1;i>=0;i--)
			s[i]==' '?ans+=1:ans+=a[s[i]-'a'];
			printf("Case #%d: %d\n", ti, ans);
	}
}
