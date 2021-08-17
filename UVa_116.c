#include <stdio.h>
#include <string.h>
#define INF 10000
int dp[10][100],a[10][100],d[10][100],n,m;
void dps (int n ,int m) {
	int ans = INF,j,sum = 0,k;
	if (m == 1) {
		for (j = 0;j < n;j++)
			if (a[j][0] < ans){
				ans = a[j][0];
				sum = j;
			}
		printf ("%d\n",sum + 1);
		printf ("%d\n",ans);
		return;
	}
	memset (dp,0,sizeof(int) * 10 * 100);
	memset (d,0,sizeof(int) * 10 * 100);
	for (j = m - 2;j >= 0;j--) {
		for (k = 0;k < n;k++){
			d[k][j] = k;
			dp[k][j] = dp[k][j+1] + a[k][j+1];
			if (k != 0 && ((dp[k-1][j+1] + a[k-1][j+1]) <= dp[k][j]))
				dp[k][j] = dp[k-1][j+1] + a[k-1][j+1],d[k][j] = k - 1;
			if (k == (n - 1) && ((dp[0][j+1] + a[0][j+1]) <= dp[k][j]))
				dp[k][j] = dp[0][j+1] + a[0][j+1],d[k][j] = 0;
			if (k != (n - 1) && ((dp[k+1][j+1] + a[k+1][j+1]) < dp[k][j]))
				dp[k][j] = dp[k+1][j+1] + a[k+1][j+1],d[k][j] = k + 1;
			if (k == 0 && ((dp[n-1][j+1] + a[n-1][j+1]) < dp[k][j]))
				dp[k][j] = dp[n-1][j+1] + a[n-1][j+1],d[k][j] = n - 1;
			if (j == 0) {
				if (dp[k][j] + a[k][j] < ans) {
					sum = k;
					ans = dp[k][j] + a[k][j];
				}
			}
		}
	}
	printf ("%d",sum + 1);
	if (m - 1 != 0) printf (" ");
	else printf ("\n");
	for (j = 0;j < m - 1;j++) {
		printf ("%d",d[sum][j] + 1);
		if (j != m - 2) printf (" ");
		else printf ("\n");
		sum = d[sum][j];
	}
	printf ("%d\n",ans);
}
int main (void) {
	int n,m,j,k;
	scanf ("%d",&n);
	while (feof (stdin) == 0) {
		scanf ("%d",&m);
		for (j = 0;j < n;j++)
			for (k = 0;k < m;k++)
				scanf ("%d",&a[j][k]);
		dps(n,m);
		scanf ("%d",&n);
	}
	return 0;
}
