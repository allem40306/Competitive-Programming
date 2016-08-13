#include <iostream>
using namespace std;
#define N 100005

int main(){
	int a[N][2], s[N], t;
	while (cin >> t){
		for (int i = 0; i < t; i++)cin >> s[i];
		a[0][0] = s[0]; a[t - 1][1] = s[t - 1];
		for (int j = 1; j < t; j++){
			a[j][0] = s[j] + a[j - 1][0];
			a[t - 1 - j][1] = s[t - 1 - j] + a[t - j][1];
		}
		int ans = 0;
		for (int k = 0; k < t; k++)
			for (int kk = 0; kk < t; kk++){
			ans += (a[k][0] == a[kk][1]);
			}
		cout << ans << endl;
	}
}