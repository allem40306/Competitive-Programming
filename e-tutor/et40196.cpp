    #include <iostream>
    using namespace std;
    #define dtx(x) (x>9?char('A'+x-10):char('0'+x))
    typedef unsigned int UI;

    void printBinary(UI x){
        for(int i=31;i>=0;i--){
            cout<<(1&(x>>i));
        }
        cout<<'\n';
    }

    void printOctal(UI x){
        cout<<0<<(x>>30);
        for(int i=0;i<10;i++){
            cout<<dtx(int(((x<<(3*i+2))>>29)));
        }
        cout<<'\n';
    }

    void printHexidecimal(UI x){
        cout<<"0x";
        for(int i=0;i<8;i++){
            cout<<dtx(int(((x<<(4*i))>>28)));
        }
        cout<<'\n';
    }

    int main(){
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);
        unsigned int ti=1,n;
        while(cin>>n){
            cout<<"Case "<<ti++<<": "<<n<<'\n';
            printBinary(n);
            printOctal(n);
            printHexidecimal(n);
        }
    }
