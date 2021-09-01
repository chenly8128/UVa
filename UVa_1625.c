#include <stdio.h>
#include <string.h>
#define INF 10000
#define N 5005
#define MAXT 100
char s1[N], s2[N];
int b1[MAXT], b2[MAXT], e1[MAXT], e2[MAXT];
int num[2][N], d[2][N];
int min (int a,int b) {
	return (a > b) ? b : a;
}
int main(void) {
        int T;
        for (scanf("%d",&T);T != 0;T--){
                scanf("%s%s",s1 + 1, s2 + 1);
                int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1),c,i;
                for(c = 'A';c <= 'Z';c++) {
			b1[c] = b2[c] = INF;
			e1[c] = e2[c] = 0;
		}
                for(i = 1;i <= len1;i++) {
                        c = s1[i];
                        b1[c] = min(i,b1[c]);
                        e1[c] = i;
                }
                for(i = 1;i <= len2;i++) {
                        c = s2[i];
                        b2[c] = min(i,b2[c]);
                        e2[c] = i;
                }
                memset(d,0,sizeof(d));
                memset(num,0,sizeof(num));
                int t = 0,j;
                for(i = 0;i <= len1;i++){
                        for(j = 0; j <= len2;j++){
                                if(i == 0 && j == 0) continue;
                                int v1 = INF;
				int v2 = INF;
                                if (i != 0) v1 = d[t ^ 1][j] + num[t ^ 1][j];
                                if (j != 0) v2 = d[t][j - 1] + num[t][j - 1];
                                d[t][j] = min(v1,v2);
                                if (i != 0) {
                                        num[t][j] = num[t^1][j];
                                        c = s1[i];
                                        if(b1[c] == i && b2[c] > j) num[t][j]++;
                                        if(e1[c] == i && e2[c] <= j) num[t][j]--;
                                }
                                if (j != 0) {
                                        num[t][j] = num[t][j-1];
                                        c = s2[j];
                                        if(b2[c] == j && b1[c] > i) num[t][j]++;
                                        if(e2[c] == j && e1[c] <= i) num[t][j]--;
                                }
                        }
                        t ^= 1;
                }
                printf("%d\n",d[t ^ 1][len2]);
        }
        return 0;
}
