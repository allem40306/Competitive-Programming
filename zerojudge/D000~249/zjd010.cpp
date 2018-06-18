#include<iostream>
using namespace std;
int main(){
	int f,sum;
	while (cin >> f){
		sum = 0;
		for (int i = 1; i <= f / 2; i++)
			if (f%i == 0)sum += i;
		if (sum == f)cout << "完全數\n";
		else cout << (sum >f ? "盈數\n" : "虧數\n");
	}
	
}