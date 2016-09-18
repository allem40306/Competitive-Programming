#include <iostream>
#include <string>
using namespace std;
#define Min(x,y) x<y?x:y
#define Max(x,y) x>y?x:y

int solve(string s1, string s2){
	int len1 = s1.size(), len2 = s2.size();
	for (int i = 0; i < len1; i++){
			int j1 = i, j2 = 0;
			while (1){
				if (j1 >= len1 || j2 >= len2)return Max(len1, len2+i);
				if (s1[j1] == '2'&&s2[j2] == '2')break;
				j1++; j2++;
			}
		}
	return len1 + len2;
}

int main(){
	string s1, s2;
	while (cin >> s1){
		cin >> s2;
		int ans = Min(solve(s1, s2), solve(s2, s1));
		printf("%d\n", ans);
	}
}