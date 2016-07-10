#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b)  {
    return a.first < b.first;
}

int main() {
    char Map[15][15];
    int Mapf[15][15];
    int x, y, cnt = 0;

    while(cin >> x) {
        if(x) cin >> y;
        else break;
        for(int i = 0; i < 15; i++) {
            for(int j = 0; j < 15; j++) {
                Map[i][j] = '*';

            }
        }
        memset(Mapf, 0, sizeof(Mapf));
        pair<int, string> p[1001];
        int cur = 0;


        for(int i = 1; i <= x; i++) {
            for(int j = 1; j <= y; j++) {
                cin >> Map[i][j];
                if(Map[i][j] == '*') {
                    Mapf[i][j] = -1;
                } else {
                    if(i - 1 < 1 || j - 1 < 1 || Map[i - 1][j] == '*' || Map[i][j - 1] == '*') Mapf[i][j] = ++cur;
                    else Mapf[i][j] = -1;
                }
            }
        }
        /*for(int i = 1; i <= x; i++) {
            for(int j = 1; j <= y; j++) {
                cout << Mapf[i][j] << " ";
            }
            cout << endl;
        }*/
        if(cnt) cout << endl;
        int last = 0;
        printf("puzzle #%d:\n", ++cnt);
        cout << "Across" << endl;
        for(int i = 1; i < 15; i++) {
            string str = "";
            for(int j = 1; j < 15; j++) {
                if(Map[i][j] != '*') {
                    if(str == "") last = Mapf[i][j];
                    str += Map[i][j];
                } else {
                    if(str != "") {//cout << "  " << last << "." << str << endl;
                        printf("%3d.", last);
                        cout << str << endl;
                    }
                    str = "";
                }

            }
        }

        cout << "Down" << endl;
        int pcu = 0;
        for(int j = 1; j < 15; j++) {
            string str = "";
            for(int i = 1; i < 15; i++) {
                if(Map[i][j] != '*') {
                    if(str == "") last = Mapf[i][j];
                    str += Map[i][j];
                } else {
                    if(str != "") {
                        p[pcu].first = last;
                        p[pcu++].second = str;
                    //cout << "  " << last << "." << str << endl;
                        str = "";
                    }
                }

            }
        }
        sort(p, p + pcu, cmp);
        for(int i = 0; i < pcu; i++) {
            printf("%3d.", p[i].first);
            cout << p[i].second<<endl;
        }
    }

    return 0;
} 