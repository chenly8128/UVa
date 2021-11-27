#include <cstdio>
int d[10005];
int main (void) {
	int a = 1,k = 1;
	for (int n = 1;n < 10005;n++) {
		if (a < n) {
			a *= 2;
			k += 1;
		}
		d[n] = k;
	}
	k = 0;
	while (scanf ("%d",&a) && a >= 0) {
		printf ("Case %d: %d\n",++k,d[a] - 1);
	}
	return 0;
}
