#include <stdio.h>
#include <string.h>
#define INF 10000
int kase=0;
int min (int x,int y) {
    return (x > y) ? y : x;
}
int main(void)
{
    int n;
    while(scanf("%d",&n)&&n!=0)
    {
        int T,M1,M2,time[n+1];
        scanf("%d",&T);
        int dp[T+1][n+1];
        int has_train[T+100][n+1][2];
        memset(has_train,0,sizeof(has_train));
        memset(time,0,sizeof(time));
        memset(dp,0,sizeof(dp));
	int i;
        for(i=1; i<n; i++)
            scanf("%d",&time[i]);
        scanf("%d",&M1);
        for(i=0; i<M1; i++)
        {
            int a,j;
            scanf("%d",&a);
            int k=a;
            for(j=1; j<=n; j++)
            {
                has_train[k][j][0]=1;
                k+=time[j];
            }
        }
        scanf("%d",&M2);
        for(i=0; i<M2; i++)
        {
            int a,j;
            scanf("%d",&a);
            int k=a;
            for(j=n; j>=1; j--)
            {
                has_train[k][j][1]=1;
                k+=time[j-1];
            }
        }
        for(i=1; i<=n-1; i++) dp[T][i]=INF;
        dp[T][n]=0;
        for(i=T-1; i>=0; i--){
	    int j;
            for(j=1; j<=n; j++)
            {
                dp[i][j]=dp[i+1][j]+1;
                if(j < n && has_train[i][j][0] && i + time[j] <= T)
                    dp[i][j]=min(dp[i][j],dp[i+time[j]][j+1]);
                if(j > 1 && has_train[i][j][1] && i + time[j-1] <= T)
                    dp[i][j]=min(dp[i][j],dp[i+time[j-1]][j-1]);
            }
	}
        printf ("Case Number %d: ",++kase);
        if (dp[0][1] >= INF) printf ("impossible\n");
        else printf ("%d\n",dp[0][1]);
    }
    return 0;
}
