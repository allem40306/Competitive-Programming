//11321 - Sort! Sort!! and Sort!!! (by Snail)
#include <iostream>
#include <algorithm>                            //for sort
using namespace std;

int m;                                          //cmp ���n�Ψ�m
//�G�ŧi������
bool cmp(int a, int b) {
	if (a%m != b%m)                             //�Y�l�Ƥ���
		return a%m < b%m;                       // ���l�ƱƧ�
	if ((a + b) % 2)                                //�Y�@�_�@��
		return abs(a % 2) >abs(b % 2);                   // �_�Ʀb�e
	if (a % 2)                                    //�P���_��
		return a > b;                           // �j�b�e
	return a < b;                               //�_�h�p�b�e
}

int main() {
	int i, n, a[10000];
	while (cin >> n >> m, n) {
		for (i = 0; i<n; i++)
			cin >> a[i];
		sort(a, a + n, cmp);
		cout << n << ' ' << m << endl;
		for (i = 0; i<n; i++)
			cout << a[i] << endl;
	}
	cout << "0 0\n";
}
