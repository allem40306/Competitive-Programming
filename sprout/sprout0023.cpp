void solve(int N,int order[]){
    int oi=0,a=1,sa=-1,ta=-1,s[10005],t[10005];
    for(;oi<N;oi++){
        while(a<=N&&a<=order[oi]){
            push_train();
            s[++sa]=a;
            a++;
        }
        while(sa>=0&&s[sa]!=order[oi]){
            move_station_1_to_2();          
            t[++ta]=s[sa]; sa--;
        }
        if(sa>=0&&s[sa]==order[oi]){
            move_station_1_to_2();
            pop_train();
			sa--;
            continue;
        }
        while(ta>=0&&t[ta]!=order[oi]){
            move_station_2_to_1();
            s[++sa]=t[ta]; ta--;
        }
        if(ta>=0&&t[ta]==order[oi]){
            pop_train();
			ta--;
            continue;
        }
        no_solution();
    }
}
