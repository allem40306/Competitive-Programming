#include <stdio.h>
 
bool isleapyear(int y){
    return (y % 4 == 0 && y % 100 || y % 400 == 0);
}
int sum(int y, int m, int d){
    int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int cnt = y * 365;
    cnt += (y - 1) / 4 + 1;
    cnt -= (y - 1) / 100 + 1;
    cnt += (y - 1) / 400 + 1;
    for(int i = 1; i < m; ++i) cnt += md[i];
    if(m > 2 && isleapyear(y)) ++cnt;
    cnt += d;
    return cnt;
}
int Count(int y1, int m1, int d1, int y2, int m2, int d2){
    return sum(y2, m2, d2) - sum(y1, m1, d1);
}
 
int main(){
    int y1, m1, d1, y2, m2, d2;
    while(scanf("%d%d%d%d%d%d", &y1, &m1, &d1, &y2, &m2, &d2) == 6){
        if (Count(y1, m1, d1, y2, m2, d2)>=0)
            printf("%d\n", Count(y1, m1, d1, y2, m2, d2));
        else
            printf("%d\n", -(Count(y1, m1, d1, y2, m2, d2)));
    }
    return 0;
}
