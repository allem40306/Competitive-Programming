#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;
string s1, s2;

int cmp(){
	int len = s1.size();
	for (int i = 0; i < len; i++){
		if (toupper(s1[i]) < toupper(s2[i]))return -1;
		if (toupper(s1[i]) > toupper(s2[i]))return 1;
	}
	return 0;
}

int main(){
	while (cin >> s1 >> s2){
		printf("%d\n", cmp());
	}
}
