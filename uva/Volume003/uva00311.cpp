#include <functional>
#include <iostream>
#include <queue>
using namespace std;
int t[7], ans, leftSpace;

bool init()
{
    int sum = 0;
    for (int i = 1; i <= 6; ++i)
    {
        cin >> t[i];
        sum += t[i];
    }
    return sum;
}

int main()
{
    cin.tie(NULL);
    while (init())
    {
        ans = t[4] + t[5] + t[6] + (t[3] + 3) / 4; // 3 * 3 to 6 * 6
        leftSpace = t[4] * 20 + t[5] * 11; // left Space of 4 * 4 and 5 * 5

        // 2 * 2 -> 4 * 4
        leftSpace -= 4 * min(t[2], t[4] * 5);
        t[2] -= min(t[2], t[4] * 5);

        // 2 * 2 -> 3 * 3
        t[3] %= 4;
        if (t[3])
        {
            leftSpace += 36 - (t[3] * 9 + 4 * min(t[2], 7 - 2 * t[3]));
            t[2] -= min(t[2], 7 - 2 * t[3]);
        }

        // 2 * 2
        if (t[2] % 9)
        {
            leftSpace += 4 * (9 - t[2] % 9);
        }
        ans += (t[2] + 8) / 9;
        t[2] %= 9;

        // 1 * 1
        t[1] -= min(t[1], leftSpace);
        ans += (t[1] + 35) / 36;
        cout << ans << '\n';
    }
}