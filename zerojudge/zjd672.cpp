#include <iostream>  
#include <cstdlib>  
#include <string>  
  
using namespace std;  
  
int main()  
{  
    string data;  
    while ( cin >> data ) {  
        if ( data.length() == 1 && data[0] == '0' )  
            break;  
        int sum = 0,flag1 = 0,flag2 = 0,temp;  
        for ( int i = 0 ; data[i] ; ++ i )  
            sum += data[i]-'0';  
        if ( sum%9 == 0 ) {  
            flag1 = 1;  
            flag2 = 1;  
        }  
        while ( sum%9 == 0 && sum > 9 ) {  
            flag2 ++;  
            temp = sum;  
            sum = 0;  
            while ( temp ) {  
                sum += temp%10;  
                temp /= 10;  
            }  
        }  
        cout << data << " is ";  
        if ( !flag1 ) cout << "not ";  
        cout << "a multiple of 9";  
        if ( flag2 ) cout << " and has 9-degree " << flag2;  
        cout << "." << endl;  
    }  
    return 0;  
}
