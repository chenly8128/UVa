#include <stdio.h>
#include <stdlib.h>
#define  MAXN 1005
struct lamp {
    int v;
    int c;
    int l;
    int k;
} la[MAXN];
int s[MAXN], n, dp[MAXN];
int min (int a,int b) {
    return (a > b) ? b : a;
}
int camp(const void * a,const void * b){
    return ((struct lamp *)(a))->v - ((struct lamp *)(b))->v;
}
int main(void) {
    while(1) {
        scanf("%d", &n);
        if(!n)
            break;

        int i, j;
        for(i = 1; i <= n; i++)
            scanf("%d%d%d%d", &la[i].v, &la[i].k, &la[i].c, &la[i].l);

        qsort(la + 1,n,sizeof (struct lamp), camp);
        for(i = 1; i <= n; i++)
        {
            s[i] = s[i - 1] + la[i].l;
        }
        for(i = 1; i <= n; i++)
        {
            dp[i] = la[i].k + la[i].c * s[i];
            for(j = 1; j < i; j++)
            {
                dp[i] = min(dp[i], dp[j] + (s[i] - s[j]) * la[i].c + la[i].k);
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
