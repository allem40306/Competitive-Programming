#include <cstdio>
#include <cstring>
int dp[6][6][6][6][6][6],num[6];

int dfs(int now){
	if(num[0]*1+num[1]*2+num[2]*3+num[3]*4+num[4]*5+num[5]*6>31)return now^1;
	if(dp[num[0]][num[1]][num[2]][num[3]][num[4]][num[5]]!=-1)
		return dp[num[0]][num[1]][num[2]][num[3]][num[4]][num[5]];
	for(int i=0;i<6;i++){
		if(num[i]<4){
			num[i]++;
			if(dfs(now^1)==(now^1)){now=(now^1); num[i]--; break;}
			num[i]--;
		}
	}
	return dp[num[0]][num[1]][num[2]][num[3]][num[4]][num[5]]=now;
}

int main(){
	char s[50]; int i,len;
	while(scanf("%s",&s)!=EOF){
		memset(dp, -1, sizeof(dp));
		memset(num,0,sizeof(num));
		for(i=0,len=strlen(s);i<len;i++)num[s[i]-'1']++;
		printf("%s %c\n",s,dfs(len%2)?'A':'B');
	}
}
