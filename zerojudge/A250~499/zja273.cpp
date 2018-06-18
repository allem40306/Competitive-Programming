#include <iostream>
using namespace std;

int main(){
	int n, k;
	while (cin >> n >> k){
		if (!n)printf("Ok!\n");
		else if (!k)printf("Impossib1e!\n");
		else printf("%s\n", n%k?  "Impossib1e!":"Ok!" );
	}
}