#include <iostream>
using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m){
		int map[201][201] = { 0 }, length[201][201] = { 0 };
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> map[i][j];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (map[i][j])   length[i][j] = length[i][j - 1] + 1;
		int Ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++){
			int w = 1e9;
			for (int h = 1; i - h >= 0 && length[i - h + 1][j]; h++){
				w = w < length[i - h + 1][j] ? w:length[i - h + 1][j];
				int area = w*h;
				Ans = area>Ans ? area : Ans;
			}
			}
		cout << Ans << endl;
	}
	return 0;
}