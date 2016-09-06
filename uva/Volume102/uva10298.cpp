#include <iostream>
#include <string>
using namespace std;
#define N 1000010


void bulid_fail_funtion(string B, int *fail){
	int len = B.length(), current_pos;
	current_pos = fail[0] = -1;
	for (int i = 1; i < len; i++){
		while (current_pos != -1 && B[current_pos + 1] != B[i]){
			current_pos = fail[current_pos];
		}
		if (B[current_pos + 1] == B[i])current_pos++;
		fail[i] = current_pos;
	}
}

int main(){
	int t, i;
	string s;
	while(cin >> s,s!="."){
		static int fail[N];
		bulid_fail_funtion(s, fail);
		int p = s.length() - 1;
		if (fail[p] != -1 && (p + 1) % (p - fail[p]) == 0)printf("%d\n", (p+1)/(p - fail[p]));
		else printf("%d\n", 1);
	}
}