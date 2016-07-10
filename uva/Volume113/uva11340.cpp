#include <iostream>
#include <stdio.h>
using namespace std;
#define N 100000

int main(){
	int n, k, m;
	while (cin >> n){
		for (int i = 0; i < n; i++){
			long long cc[N] = {}, price, to = 0;
			cin >> k;
			unsigned char ch;
			char str[N];
			while (k--){
				cin >> ch;
				cin>>cc[ch];
			}
			cin >> m >> ws;
			while (m--){
				gets(str);
				for (int si = 0; str[si]; si++)
					if(str[si]!=' ')to += cc[str[si]];
			}
			printf("%.2lf$\n", to / 100.0);
		}
	}
}