#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

void bulid_fail_funtion(string B, int *fail){
	int len = B.length(), current_pos;
	current_pos = fail[0] = -1;
	for (int i = 1; i<len; i++){
		while (current_pos != -1 && B[current_pos + 1] != B[i]){
			current_pos = fail[current_pos];
		}
		if (B[current_pos + 1] == B[i])current_pos++;
		fail[i] = current_pos;
	}
}

int match(string A, string B, int *fail){
	int lenA = A.length(), lenB = B.length();
	int current_pos = -1;
	for (int i = 0; i< lenA; i++){
		while (current_pos != -1 && B[current_pos + 1] != A[i]){
			current_pos = fail[current_pos];
		}
		if (B[current_pos + 1] == A[i])current_pos++;
	}
    return current_pos;
}

int main(){
    static int fail[N];
	string s, r;
    while(cin >> s){
        r = s;
        reverse(r.begin(), r.end());
        bulid_fail_funtion(r, fail);
        int res = match(s, r, fail);
        cout << s;
        for(int i = res + 1; i < r.size(); ++i){
            cout << r[i];
        }
        cout << '\n';
    }
}