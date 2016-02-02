#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1001][1001];
string a;

int findmin(int i,int j){
	if (dp[i][j] == -1){
		if (i >= j)dp[i][j] = 0;
		else{
			if (a[i] == a[j]){
				dp[i][j] = findmin(i + 1, j - 1);
			}
			else{
				dp[i][j] = min(findmin(i + 1, j - 1), min(findmin(i + 1, j), findmin(i, j - 1))) + 1;
			}
		}
	}
	return  dp[i][j];
}

int main() {
	int n, t = 1;
	cin >> n;
	while (n--){
		cin >> a;
		memset(dp, -1, sizeof(dp));
		printf("Case %d: %d\n", t++, findmin(0, a.size() - 1));
	}
}