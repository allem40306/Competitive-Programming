#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	for (a = 100; a < 500; a++)
		for (b = a + 1; b < 500; b++)
			for (c = b + 1; c < 500; c++)
				if ((a + b + c == 1000) && (a*a + b*b == c*c))
					printf("%d\n", a*b*c);
}