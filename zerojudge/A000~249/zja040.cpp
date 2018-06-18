#include <iostream>
using namespace std;

int main()
{
	int a, b, i, index;
	int arr[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 153, 370, 371, 407, 1634, 8208, 9474, 54748, 92727, 93084, 548834 };

	index = 20;
	while (cin >> a >> b)
	{
		for (i = 0; i<index && a>arr[i]; i++);
		b++;
		if (b > arr[i])
		{
			for (; i<index && b>arr[i]; i++)
				cout << arr[i] << " ";
			cout << endl;
		}
		else
			cout << "none\n";
	}
	return 0;
}
