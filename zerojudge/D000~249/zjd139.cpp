#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main(){
	char in[1010];
	while (cin >> in){
		int n = strlen(in), c = 1;   
		for (int i = 0; i<n; i++){
			if (in[i] == in[i + 1]){
				c++;
			}
			else{
				if (c == 1)
					cout << in[i];
				else if (c == 2)
					cout << in[i] << in[i];
				else
					cout << c<< in[i];
				c = 1;
			}
		}
		cout << endl;
	}

}