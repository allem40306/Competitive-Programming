#include <iostream>
#include <string>
using namespace std;
#define N 1005

int main(){
	string s[N], s1 = "ACGT";
	int t,ti = 0,n,m;
	for (cin >> t; ti < t; ti++){
		cin >> n >> m;
		int ans = 0; string s2 = "";
		for (int i = 0; i < n; i++)cin >> s[i];
		for (int i = 0; i < m; i++){
			int a[4] = {};
			for (int j = 0; j < n; j++){
				if (s[j][i] < 'D')
					s[j][i] == 'A' ? a[0]++ : a[1]++;
				else
					s[j][i] == 'G' ? a[2]++ : a[3]++;
			}
			int maxi = 0, maxv = 0;
			for (int k = 0; k < 4; k++){
				if (a[k]>maxv){ maxi = k; maxv = a[k]; }
			}
			s2 += s1[maxi]; ans += n - maxv;
		}
		cout << s2; printf("\n%d\n",ans);
	}
}