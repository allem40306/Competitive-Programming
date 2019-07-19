#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t >> ws;
    while(t--)
    {
        int x1, y1, x2, y2;
        double dist = 0.0;
        string s;
        cin >> ws;
        getline(cin, s);
        while(getline(cin, s))
        {
            if(s.empty())
            {
                break;
            }
            stringstream ss(s);
            ss >> x1 >> y1 >> x2 >> y2;
            dist += hypot(x1 - x2, y1 - y2);
        }
        dist /= 1000; // m -> km
        double hours = dist * 2 / 20;
        double minutes = round(hours * 60);
        printf("%d:%02d\n", int(minutes) / 60, int(minutes) % 60);
        if(t)cout << '\n';
    }
}