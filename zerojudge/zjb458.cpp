#include <iostream>
using namespace std;

int main(){
	long long int t, r, g, b, h, w;
	while (cin >> t){
		cin >> h >> w;
		printf("%d %d\n", h, w);
		for (int i = 0; i < w; i++){
			for (int j = 0; j < h; j++){
				if (j)printf(" ");
				cin >> r >> g >> b;
				printf((r+g+b) < t*3 ? "0 0 0" : "255 255 255");
			}
			printf("\n");
		}
	}
}