#include <bits/stdc++.h>
using namespace std;

int main()
{
    int D, a, b, c;
    int tota = 0, totb = 0, totc = 0;
    cin >> D;
    while(D--)
    {
        cin >> a >> b >> c;
        tota += a;
        totb += b;
        totc += c;
        int mn = min(tota, min(totb, totc));
        if(mn < 30)
        {
            cout << "NO\n";
        }
        else
        {
            cout << mn << '\n';
            tota -= mn;
            totb -= mn;
            totc -= mn; 
        }
        
    }
}