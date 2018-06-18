#include<stdio.h>
#include<string.h>

void walk(int n, int floor, bool *used){
	if (floor == 9){
		printf("%d\n", n);
	}
	else {
		n *= 10;
		for (int i = 1; i<10; i++){
			if (!used[i] && (n + i) % (floor + 1) == 0){
				used[i] = 1;
				walk(n + i, floor + 1, used);
				used[i] = 0;
			}
		}
	}
}

int main(){
	bool T[15];
	memset(T, 0, sizeof(T));
	walk(0, 0, T);
}