#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define M 1005
#define Mod 1000
int p[M], sum, ans, h, l;
	
void init(){
	for(int i = 0; i < M; i++)
		p[i] = 0;
	h = l = ans, sum = 0;
	return;
}

int main(){
	int n, x, y;
	char ch;
	while (cin >> n,n){
		init();
		for (int i = 0; i < n; i++){
			cin >> x >>ch>> y;
			p[i] = x * Mod + y*10;
			sum += p[i];
		}
		sum = sum / n;
		for (int i = 0; i < n; i++){
			if (sum < p[i])h += p[i] - sum;
			if (sum > p[i])l += sum - p[i];
		}
		if (h < l)printf("$%d.%s%d\n", h / Mod, (h % Mod)/10 < 10 ? "0" : "", h % Mod/10+(h%10>=5));
		else printf("$%d.%s%d\n", l / Mod, (l % Mod)/10 < 10 ? "0" : "", l % Mod/10+(l%10>=5));
	}
}