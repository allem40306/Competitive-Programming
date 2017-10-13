#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
	int a, b;
	while (cin >> a){
		srand(time(NULL));
		b = (rand() % 100) + 1;
		while (a != b){
			printf("ans is not %d\n", b);
			b = (rand() % 100) + 1;
		}
		printf("bingo! it is %d\n",b);
	}
}
