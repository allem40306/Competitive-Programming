#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, N, L;
    vector<int> v;
    cin >> T;
    for(int ti = 1; ti <= T; ++ti)
    {
        cin >> N >> L;
        v.resize(N);
        for(int i = 0; i != N; ++i)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int tot = 0, lastT = 0, totT = 0;
        for(int i = 0; i != N; ++i)
        {
            if(lastT + v[i] > L)
            {
                break;
            }
            ++tot;
            lastT += v[i];
            totT += lastT;
        }
        cout << "Case " << ti << ": " << tot << ' ' << lastT << ' ' << totT << '\n';
    }
}