#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
int arr[1010], heapp[600000];
int bp;

int bulit(int L, int R, int x){
	if (R - L == 0)return 0;
	if (R - L == 1)return arr[L];
	int M = (L + R) / 2;
	heapp[bp++] = bulit(L, M, x) + bulit(M, R, x);
	if ()

}

int modfiy(int L, int R){

}

int quest(int L, int R){

}

int main() {
	int n, t = 0;
	while (scanf("%d", n)){
		if (t)printf("\n");
		printf("Case %d", ++t);
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n; i++)scanf("%d", arr[i]);
		int bp = 0;
		bulit(0, n, 1);
		string s, x, y;
		while (scanf("%s", s), s != "END"){
			cin >> x >> y;
			if (s == "S")modfiy(0, n, x, y);
			else if (s == "M")quest(0, n, x, y);
		}
	}
}