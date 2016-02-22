#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;
#define chi(ch) int(ch-'A')
#define mp make_pair

struct matrix{
	int row, col;
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
	pair<int, int> a, b;
	cin >> ws;
	while (cin >> s){
		int ans = 0;
		stack <pair<int, int>> st;
		int lens = s.size();
		for (int i = 0; i < lens&&ans != -1; i++){
			if (s[i] == '(' && (s[i + 1] == ')' || s[i + 2] == ')')){
				ans = -1;
				break;
			}
			if (isalpha(s[i])){
				int a = chi(s[i]);
				st.push(mp(chain[a].row, chain[a].col));
			}
			else if (s[i] == ')'){
				b = st.top(); st.pop();
				a = st.top(); st.pop();
				if (a.second == b.first){
					ans += a.first*a.second*b.second;
					st.push(mp(a.first, b.second));
				}
				else if (b.second == a.first){
					ans += b.first*b.second*a.second;
					st.push(mp(b.first, a.second));
				}
				else{
					ans = -1;
					break;
				}
			}
		}
		if (st.size() > 1 || ans == -1)printf("error\n");
		else printf("%d\n", ans);
	}
}