#include <iostream>
using namespace std;

int  GCD(int a, int b){ /* GCD()���@�ӨD��ӿ�J�Ʀr���̤j���]�ƪ����*/
	int t;
	while (b){
		t = a%b, a = b, b = t;
	}
	return a;
}

int main(){
	int N, G, i, j;
		while (cin >> N, N){
		G = 0;
		for (i = 1; i<N; i++)
			for (j = i + 1; j <= N; j++){
			G += GCD(i, j);
			}
		cout << G << endl;
	}
}
