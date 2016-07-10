#include <iostream>
#include <string>
using namespace std;
#define N 500
int main(){
	int n, k;
	while (cin >> n, n){
		int a[N], b[N][N];
		for (int i = 1; i <= n; i++)cin >> a[i],b[0][i]=i,b[1][i]=a[i];
		for (int i = 2; i <= n; i++){;
			for (int j = 1; j <= n; j++)
				b[i][j] = b[i - 1][b[i - 1][j]];
		}
		while (cin >> k, k){
			string s;
			getline(cin, s);
			int lens = s.size();
			int mo = k%n;
			for (int kk = 1; kk <= n; kk++){
				if (b[mo][kk] >= lens)printf(" ");
				else cout << s[b[mo][kk]-1];
			}
			cout << endl;
		}
		cout << endl;
	}
}