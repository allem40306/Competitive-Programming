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
    int ti = 0, n;
	string s;
	while(cin >> n, n){
		static int fail[N];
        cin >> s;
		bulid_fail_funtion(s, fail);
        cout << "Test case #" << ++ti << '\n';
        for(int i = 1; i < (int)s.size(); ++i){
            if(fail[i] != -1 && (i + 1) % (i - fail[i]) == 0){
                cout <<  i + 1 << ' ' << (i + 1) / (i - fail[i]) << '\n';
            }
        }
        cout << '\n';
	}
}