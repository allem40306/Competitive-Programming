#include <iostream>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;
#define N 200+2
int dp[N][N], arr[N][N];

int largest_empty_rectangle(int n, int m){
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++){
		if (arr[j][i] == 1)
			dp[j][i] = dp[j - 1][i] + 1;
		}
	int maxarea = 0, nowh = 0;
	for (int i = 1; i <= n; i++){
		stack <pair<int, int>> st;
		st.push(make_pair(0, 0));
		for (int j = 1; j <= m + 1; j++){
			if (dp[i][j] > nowh){
				nowh = dp[i][j];
				st.push(make_pair(j, nowh));
			}
			else if (dp[i][j] < nowh){
				nowh = dp[i][j];
				pair <int, int> p = st.top();
				st.pop();
				maxarea = max(maxarea, p.second*(j - p.first));
			}
		}
	}
	return maxarea;
}

void init(){
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++){
		arr[i][j] = 0;
		dp[i][j] = 0;
		}
}

int main() {
	int n, m;
	while (cin >> n >> m){
		init();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> arr[i][j];
		printf("%d\n", largest_empty_rectangle(n, m));
	}
}