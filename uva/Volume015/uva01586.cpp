#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double qq(char ch){
	if (ch == 'C')return 12.01;
	if (ch == 'H')return 1.008;
	if (ch == 'O')return 16.00;
	return 14.01;
}

int main() {
	int n, ni = 0;
	string s;
	for (cin >> n; ni < n; ni++){
		double q = 0, ans = 0;
		cin >> s;
		int lens = s.size(), t = 0;
		for (int i = 0; i < lens; i++){
			if (isalpha(s[i])){
				ans += q*(t ? t : 1);
				t = 0;
				q = qq(s[i]);
			}
			else{
				t = t * 10 + (s[i] - '0');
			}
		}
		ans += q*(t ? t : 1);
		printf("%.3lf\n", ans);
	}
}