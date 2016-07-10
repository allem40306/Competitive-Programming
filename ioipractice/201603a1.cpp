#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main(){
	int n;
	cin >> n;
	while (n--){
		string s[4][13];
		int p[13] = { 0 }, x = 0, d = 1, ans = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 13; j++)
				cin >> s[i][j];
		while (1){
			ans++;
			if (ans == 52)break;
			if (s[p[x]][x] == "AS")break;
			int xx = x, ti;
			if (isdigit(s[p[x]][x][0])){ti = 3;}
			else if (s[p[x]][x][0] == 'A'){d *= -1;ti = 2;}
			else{ ti = 2; }
			p[xx]++;
			while (ti--){
				if (x = (x + d + 13) % 13, p[x] > 3)
					ti++;
			}
		}
		cout << ans << endl<<endl;
	}
}