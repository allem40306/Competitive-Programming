#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000000
unsigned long long lis[N][2], h[N], n, ans;

void init(){
	for (int i = 0; i < n; i++)
		lis[i][0]=lis[i][1] = 0;
	ans = 0;
	return;
}

int main(){
	int n;
	cin >> n;
	init();
	for (int i = 0; i < n; i++)cin >> h[i];
	for (int j = 0; j < n; j++)
		for (int k = j+1; k < n; k++){
		if (h[j] <= h[k]){
			lis[k][0] = (lis[k][0] > lis[j][0] + 1 ? lis[k][0] : lis[j][0] + 1);
			}
		}
	for (int j = n-1; j>=0; j--)
		for (int k = j - 1; k >= 0; k--){
		if (h[j] <= h[k]){
			lis[k][1] = (lis[k][1] > lis[j][1] + 1 ? lis[k][1] : lis[j][1] + 1);
			}
		}
	for (int i = 0; i < n; i++)
		ans += lis[i][0] + lis[i][1];
	cout << ans << endl;
}