#include <iostream>
using namespace std;
#define N 50000000

int main(){
	int n, b, h, w;
	while (cin >> n >> b >> h >> w){
		int ans = N;
		for (int i = 0; i < h; i++){
			int c, p;
			cin >> c;
			for (int j = 0; j < w; j++){
				cin >> p;
				if (p >= n&&c*n <= b&&c*n <= ans)
					ans = c*n;
			}
		}
		if (ans == N)printf("stay home\n");
		else printf("%d\n", ans);
	}
}