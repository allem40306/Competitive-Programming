#include<iostream>
#include<string>

using namespace std;

int main(){
    string db[21][2] ;
    string s, s1 ;
    int c, q, j=0;
    while(cin>>c>>q){
        if(j++) cout << endl ;
        for(int i=0 ; i<c ; ++i)
            cin >> db[i][0] >> db[i][1] ;

        for(int i=0 ; i<q ; ++i){
            cin >> s >> s1 ;
            if(s=="brand"){
                for(int i=0 ; i<c ; ++i)
                    if(db[i][0]==s1)
                        cout << db[i][0] << " " << db[i][1] << endl ;
            }
            else{
                for(int i=0 ; i<c ; ++i)
                    if(db[i][1]==s1)
                        cout << db[i][0] << " " << db[i][1] << endl ;
            }
        }
    }
    return 0 ;
}