#include <iostream>
#include <string>
using namespace std;

int main() {
	int sr = 0, len[16], mlen = 0;
	string s[16], r;
	while (getline(cin,r)){
		if (r == "END")break;
		len[sr] = r.size();
		if (len[sr] > mlen)mlen = len[sr];
		s[sr++] = r;
	}
	for (int i = 0; i < mlen; i++){
		for (int j = 0; j < sr; j++){
			if (j)printf("  ");
			if (i < len[j])printf("%c", s[j][i]);
			else printf(" ");
		}
		printf("\n");
	}
}