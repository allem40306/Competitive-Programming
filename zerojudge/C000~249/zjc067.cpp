#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, i, h[50], a, m, tc = 1;                //�}�C h �n�� 50 �Ӥ���
	while (cin >> n, n) {
		a = 0;
		for (i = 0; i<n; i++) {
			cin >> h[i];                        //��J����
			a += h[i];                          //�å[�`
		}
		a /= n;                                 //�D��������
		m = 0;                                  //m(oves)--���ʭӼ�
		for (i = 0; i<n; i++)
			m += max(0, h[i] - a);             //�W�X�������ת��Ӽ�
		cout << "Set #" << tc++ << endl;        //���D�N�n�D��X
		cout << "The minimum number of moves is " << m << ".\n\n";
	}
}
