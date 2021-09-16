#include <stdio.h>
#include <string.h>
#define maxn 110
#define INF 100000
char s[maxn];
int dp[maxn][maxn];
_Bool match(int i,int j) {
        if((s[i] == '(' && s[j] == ')') ||(s[i] == '[' && s[j] == ']')) return 1;
        return 0;
}
int min (int j,int i) {
	return (j > i) ? i : j;
}
void dps(int len) {
	int i,j,k;
        for(i = 0; i < len; i ++) {
                dp[i][i] = 1;
                dp[i+1][i] = 0;
        }
        for(i = len - 2; i >= 0; i --){
                for(j = i + 1; j < len; j ++) {
                        dp[i][j] = j - i + 1;
                        if(match(i,j))
                        dp[i][j] = min(dp[i][j],dp[i+1][j-1]);
                        for(k = i; k < j; k++)
                                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
        }
}
void p(int i,int j) {
	int k;
        if(i > j) return;
        if(i == j)
        {
                if(s[i] == '(' || s[i] == ')')
                printf ("()");
                else printf ("[]");
                return;
        }
        int ans = dp[i][j];
        if(match(i,j) && ans == dp[i+1][j-1]){
                printf ("%c",s[i]);
                p(i+1,j-1);
                printf ("%c",s[j]);
                return;
        }
        for(k = i; k < j; k ++)
        {
                if(ans == (dp[i][k] + dp[k + 1][j]))
                {

                        p(i,k);
                        p(k + 1,j);
                        return;
                }
        }
}
int main(void) {
        int step,i;
        scanf("%d",&step);
        getchar();
        for(i = 1;i <= step;i++) {
                memset(dp,0,sizeof(dp));
                gets(s);
                gets(s);
                int len = strlen(s);
                dps(len);
                p(0,len - 1);
                printf ("\n");
                if(i < step) puts("");
        }
        return 0;
}
