#include <stdio.h>
#include <string.h>
#define MAXN 1005
#define MAXT 10
int min (const int a,const int b) {
	return (a > b) ? b : a;
}
int main (void) {
	int a[MAXN],b[MAXN];
	int shuliang [MAXT],liang[MAXT];
	int n,step = 0;
	int j;
	while (scanf ("%d",&n) && (n != 0)) {
		printf ("Game %d:\n",++step);
		memset (shuliang,0,sizeof (int) * MAXT);
		for (j = 0;j < n;j++) {
			scanf ("%d",a + j);
			shuliang [a[j]]++;
		}
		while (1) {
			int A = 0,B = 0,c[MAXT];
			memcpy (c,shuliang,sizeof (int) * MAXT);
			memset (liang,0,sizeof (int) * MAXT);
			for (j = 0;j < n;j++) {
				scanf ("%d",b + j);
				if (b[j] != a[j]) {
					liang [b[j]]++;
				}
				else {
					A++;
					c[a[j]]--;
				}
			}
			if (b[0] == 0) break;
			for (j = 0;j < MAXT;j++) {
				B += min (liang[j],c[j]);
			}
			printf ("    (%d,%d)\n",A,B);
		}
	}
	return 0;
}
