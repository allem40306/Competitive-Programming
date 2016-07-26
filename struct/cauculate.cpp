#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string s;
	while (cin >> s){
		stack <char> st, mp;
		int lens = s.size();
		string r;
		for (int i = 0; i < lens; i++){
			if (s[i] == ' ')continue;
			if (s[i] == '+' || s[i] == '-')
				mp.push(s[i]);
			else if (s[i] == '*' || s[i] == '/' || s[i] == '%'){
				char ch = st.top(); st.pop();
				char ch2 = st.top(); st.pop();
				r += ch2 + ch + s[i];
			}
			else if (s[i] == ')'){
				while (1){
					if (st.top() == '(')break;
					r += st.top();	st.pop();
				}
				st.pop();
			}
			else st.push(s[i]);
		}
		cout << r << endl;
	}
}