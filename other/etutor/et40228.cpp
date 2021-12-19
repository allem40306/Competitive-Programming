#include <iostream>
using namespace std;
int mdays[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};

class Date{
private:
    int m,d,y;
	static inline bool is_leap_year(int y){
	    return (y%400==0||(y%4==0&&y%100));
	}
	int monthDays(int m){
		return mdays[m];
	}
public:
    Date(int = 1,int = 1,int = 2000){}
    void print(){
        cout<<m<<'-'<<d<<'-'<<y<<'\n';
    }
    void setMouth(int mm){
        m=mm;
    }
    void setDay(int dd){
        d=dd;
    }
    void setYear(int yy){
        y=yy;
    }
    void setDate(int mm,int dd,int yy){
         setMouth(mm);
         setDay(dd);
         setYear(yy);
    }
    int getMonth(){
        return m;
    }
    int getDay(){
        return d;
    }
    int getYear(){
        return y;
    }
    void nextDay(){
        d++;
        if(m==2&&d==29&&is_leap_year(y))return;
        if(d>monthDays(m)){
            m++;
            if(m>12){y++;m=1;}
            d=1;
        }
        return;
    }
};

int main(){
    int yy,mm,dd,days;
    cin>>mm>>dd>>yy>>days;
    Date date;
    date.setDate(mm,dd,yy);
    while(days--){
        date.print();
        date.nextDay();
    }
}
