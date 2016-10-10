#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double gr, r, g, b, h, w;
	while (cin >> w >> h){
		printf("%.0f %.0f\n", w, h);
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				if (j)printf(" ");
				cin >> r >> g >> b;
				gr = round((r + g + b) / 3);
				printf("%.0f %.0f %.0f", gr, gr, gr);
			}
			printf("\n");
		}
	}
}