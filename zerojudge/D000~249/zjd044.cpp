#include <iostream>
using namespace std;
#define N 1000000
int s[N+5];

int d(int j){
	int summ = 0;
	while (j){ summ += (j% 10); j /= 10; }
	return summ;
}

void bulit(){
	for (int i = 0; i <= N; i++)
		s[i]= 1;
	for (int j = 1; j < N; j++){
		int g = j + d(j);
		if (g < N + 5)s[g] = 0;
	}
	return;
}

int main(){
	bulit();
	for (int i = 1; i <= N; i++){
		if (s[i])printf("%d\n", i);
	}	
}