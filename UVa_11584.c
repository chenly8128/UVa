#include <stdio.h>
#include <string.h>
#define MAXN 1005
int d[MAXN],m,n;
_Bool b[MAXN][MAXN];
char s[MAXN];
int main (void) {
  int j,k;
  for (scanf ("%d",&m);m > 0;m--) {
    scanf ("%s",s);
    n = strlen (s);
    for (j = 0;j < n;j++) {
      b[j+1][j-1] = b[j][j-1] = 1;
      b[0][0] = 1;
      for (k = j;k >= 0 && j > 0;k--)
	if (b[k+1][j-1] && (s[k] == s[j])) {
	  b[k][j] = 1;
	}
	else {
	  b[k][j] = 0;
	}
      b[j+1][j-1] = b[j][j-1] = 0;
    }
    for (j = 0;j < n;j++) {
      d[j] = j + 1;
      for (k = j - 1;k >= -1;k--)
	if (b[k+1][j] && (d[j] > (d[k] + 1))) d[j] = d[k] + 1;
    }
    printf ("%d\n",d[n-1]);
  }
  return 0;
}
