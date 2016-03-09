#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;
#define chi(ch) int(ch-'A')
#define mp make_pair

struct matrix{
	int row, col;
	matrix(int a = 0, int b = 0) :row(a), col(b){}
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
		stack <matrix> st;
		int lens = s.size();
		for (int i = 0; i < lens&&ans != -1; i++){
			if (isalpha(s[i]))
				st.push(chain[s[i]-'A']);
			else if(s[i] == ')'){
				matrix b = st.top(); st.pop();
				matrix a = st.top(); st.pop();
				if (a.col != b.row){ans = -1;break;}
					ans += a.row*a.col*b.col;
					st.push(matrix(a.row, b.col));
			}
		}
		if (ans == -1)printf("error\n");
		else printf("%d\n", ans);
	}
}