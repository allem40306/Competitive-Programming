//a022 �j��

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){

	string i, ii;
	int a;
	while (cin >> i){
		a = i.size();
		if (a % 2)     //�Y�r����׬��_��
			i.erase(a / 2, 1); //�N�����r������ ( ���b�o�D�����������r���S�h�j�N�q =="" )
		ii = i;
		reverse(i.begin(), i.end());         //�N�r��˹L�ӱ�

		if (i == ii)                   //�p�G�˹L�ӫ�r��P��ۦ�ۦP
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}

//reverse�Ϊk
//��#include <algorithm>
//�]�r�� a;
//reverse(�q�r�ꤤ��s�ӰO�����m, ��r�ꤤ��d�ӰO�����m)
//�h �q a[s] �� a[d]�|�˹L�ӱ�