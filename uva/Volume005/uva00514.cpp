#include <iostream>
#include <stack>
using namespace std;

int main(){
	int n, s[1010];
	while (cin >> n, n){
		while (cin >> s[1], s[1]){	
		int a = 1, b = 1, ok = 1;	
		stack <int> ss;
		for (int i = 2; i <= n; i++)
			cin >> s[i];
		while (b <= n){
			if (a == s[b]){ a++, b++; }
			else if (!ss.empty()&&ss.top() == s[b]){ ss.pop(); b++; }
			else if (a <= n)ss.push(a++);
			else { ok = 0; break; }
		}
		cout << ((ok) ? "Yes\n" : "No\n");
	}
	cout << endl;
	}
}
