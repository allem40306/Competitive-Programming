//a020: ®≠§¿√“¿À≈Á by Snail
#include <iostream>
using namespace std;

int main () {
     int id, cs, i;
     char c;
     while (cin >> c) {
           if (c == 'I')
                cs = 34;
           else if (c == 'O')
                cs = 35;
           else if (c == 'W')
                cs = 32;
           else if (c == 'Z')
                cs = 33;
           else {
                cs = c - 55;
                if (c > 'I')
                     cs--;
                if (c > 'O')
                     cs--;
                if (c > 'W')
                     cs--;
           }
           cs = cs%10 * 9 + cs / 10;
           cin >> id;
           cs += id % 10;
           id /= 10;
           for (i=1; i<=8; i++) {
                cs += id%10 * i;
                id /= 10;
           }
           if (cs % 10)
                cout << "fake\n";
           else
                cout << "real\n";
     }
}