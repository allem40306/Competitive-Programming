#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
int arr[1010];
int heapp[600000]; 

int bulit(int x,int R,int L){
	if (L - R == 0)return 0;
	if (L - R == 1)return arr[L];

}

int main() {
	int n, t = 0;
	while (scanf("%d",n)){
		if (t)printf("\n");
		printf("Case %d", ++t);
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n; i++)scanf("%d", arr[i]);
		bulit(1,0,n);
		string s, x, y;
		while (scanf("%s",s), s != "END"){
			if (s == "S");
			else if (s == "M");
		}
	}
}
