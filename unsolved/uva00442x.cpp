#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;
#define chi(ch) int(ch-'A')

struct matrix{
	int row, col;
	matrix(int a, int b) : row(a), col(b){}
}chain[30];

void init(){
	int n;
	char ch;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> ch;
		cin >> chain[chi(ch)].row >> chain[chi(ch)].col;
	}
	return;
}

int main(){
	init();
	string s;
	cin >> ws;
	while (getline(cin, s)){
		int ans = 0;
		stack <matrix> st;
		int lens = s.size();
		for (int i = 0; i < lens&&ans != -1; i++){
			if (isalpha(s[i])){
				int a = chi(s[i]);
				st.push(matrix(chain[a].row, chain[i].col));
			}
			else if (s[i] == ')'){
				chain[27] = st.top(); st.pop();
				chain[26] = st.top(); st.pop();
				if (chain[26].col != chain[27].row){
					ans = -1;
					break;
				}
				ans += chain[26].row * chain[27].row * chain[26].col;
				st.push(matrix(chain[26].row, chain[27].col));
			}
		}
		if (ans == -1)printf("error\n");
		else printf("%d\n", ans);
	}
}