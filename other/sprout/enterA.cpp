#include <iostream>
#include <string>
using namespace std;
bool b[10];

bool d2(int i){
	while (i){
		if (!b[i % 10])return 0;
		i /= 10;
	}
	return 1;
}

int d1(int i){
	if(!i)
	if(b[i])return i;
	else i++;
	while (1){
		if (d2(i))return i;
		i++;
	}
}

int main(){
	string s;
	int n, t, ti = 0;
	for (scanf("%d", &t); ti<t; ti++){
		cin >> n >> s;
		for (int i = 0; i<10; i++)
			if (s[i] == '0')b[i] = 0;
			else b[i] = 1;
			printf("%d\n", d1(n));
	}
}
