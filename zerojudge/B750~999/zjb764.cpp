#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	while (cin >> n){
		for (int ni = 0; ni < n; ni++){
			string s;
			cin >> s;
			int lens = s.size();
			int a[6], ar = 0, t = 0, t2;
			bool na, nb;
			na = nb = false;
			for (int i = 0; i < lens;){
				if (t > 4){
					t = t * 2 + (s[i] - '0') - 2;
					a[ar++] = t;
					t = 0; i++;
				}
				else if (s[i] == '1')t++, i++;
				else if (t){
					if (ar < 4){
						i++;
						t = t * 2 + (s[i] - '0')-2;
						a[ar++] = t;
						t = 0; i++;
					}
					else{
						i++;
						t = t * 2 + (s[i] - '0') - 2;
						t2 = t; t = 0; i++;
					}
				}
				else {
					if (s[i + 1] == '0'){ na = true; a[4] = t2; t2= 0; }
					else { nb = true; a[5] = t2; t2 = 0; }
					i += 2;
				}
			}
			for (int i = 0; i < 4; i++)printf("%d", a[i]);
			printf(",");
			if (na)printf("%dA", a[4]);
			if (nb)printf("%dB", a[5]);
			printf("\n");
		}
	}
}