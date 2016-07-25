#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--){
		string s;
		stack <char> st;
		cin >> s;
		int ans = 0, lens = s.size();
		for (int i = 0; i < lens; i++){
			if (ans == -1)break;
			if (s[i] == '('){
				ans++;
				st.push('(');
			}
			else{
				if (!st.empty())st.pop();
				else{ ans = -1; }
			}
		}
		if (ans == -1 || !st.empty())printf("0\n");
		else printf("%d\n", ans);
	}
}