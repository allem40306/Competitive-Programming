#include<iostream>
using namespace std;
int main() {
	int n, i, count, begin;      //begin因數分解的開始，1表示開始，0表示不是第ㄧ個因數輸出
	while (cin >> n){
		i = 2;
		begin = 1;
		while (i <= n){
			count = 0;                  //count為紀錄因數的個數
			while (n%i == 0){
				count++;
				n /= i;
			}
			if (begin == 1){
				if (count > 1){
					cout << i << "^" << count;
					begin = 0;
				}
				else if (count == 1){
					cout << i;
					begin = 0;
				}
			}
			else {
				if (count > 1){
					cout << " * " << i << "^" << count;
				}
				else if (count == 1){
					cout << " * " << i;
				}
			}
			i++;
		}
		cout << endl;
	}
	//system("pause");
}
