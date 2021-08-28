#include<stdio.h>
#define maxt 10000
#define maxn 100
int dp[maxt];
int val[maxt];
int n,t;
int num[maxn];
int max (int x,int y) {
	return ((x > y) ? x : y);
}
int main(void)
{
        int T,Case=1;
        scanf("%d",&T);
        while(T--)
        {
                scanf("%d%d",&n,&t);
                int maxx=0,i,j;
                for(i=1;i<=n;i++)
                {
                        scanf("%d",&num[i]);
                }
                for(i=1;i<=t;i++)
                {
                        dp[i]=0;
                        val[i]=0;
                }
                for(i = 1;i <= n;i++)
                {
                        for(j = t - 1;j >= num[i];j--)
                        {
                                if(dp[j-num[i]] >= 1 || (j - num[i]) == 0)
                                {
                                        dp[j] = max(dp[j],dp[j-num[i]]+1);
                                }
                                maxx=max(dp[j],maxx);
                        }
                }
                for(j = t - 1;dp[j] != maxx;j--);
                if(maxx == 0)
                {
                        printf("Case %d: %d %d\n",Case++,maxx + 1,678);
                }
                else
                {
                        printf("Case %d: %d %d\n",Case++,maxx + 1,678 + j);
                }
        }
        return 0;
}
