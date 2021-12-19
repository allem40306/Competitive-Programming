#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const int N = 731;
char ans[N][N];

void print(int n, int x, int y)
{
    if (n == 1)
    {
        ans[x][y] = 'X';
        return;
    }
    int m = pow(3.0, n - 2);
    print(n - 1, x, y);
    print(n - 1, x + m, y + m);
    print(n - 1, x + 2 * m, y + 2 * m);
    print(n - 1, x, y + 2 * m);
    print(n - 1, x + 2 * m, y);
}

int main()
{
    int n;
    while (cin >> n, n != -1)
    {
        int m = pow(3.0, n - 1);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                ans[i][j] = ' ';
            }
        }
        print(n, 0, 0);
        for (int i = 0; i < m; ++i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                if (ans[i][j] == ' ')
                {
                    ans[i][j] = '*';
                }
                else
                {
                    break;
                }
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (ans[i][j] == '*')
                {
                    break;
                }
                printf("%c", ans[i][j]);
            }
            printf("\n");
        }
        printf("-\n");
    }
}