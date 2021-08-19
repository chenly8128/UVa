#include <stdio.h>
struct lifangti {
  int x,y,z,
    len;
} dp[90];
int ans,size;
void dps (int s) {
  _Bool b = 0;
  int j;
  for (j = 0;j < size;j++) {
    if (((dp[s].x > dp[j].x) && (dp[s].y > dp[j].y))
        || ((dp[s].y > dp[j].x) && (dp[s].x > dp[j].y))) {
      b	= 1;
      if (dp[j].len == 0) dps(j);
      dp[s].len	= (dp[j].len + dp[s].z) > dp[s].len ? (dp[j].len + dp[s].z) : dp[s].len;
    }
  }
  if (!b) dp[s].len = dp[s].z;
}
int main (void) {
  int step = 0;
  while (1) {
    scanf ("%d",&size);
    if (size == 0) break;
    int j;
    size *= 3;
    ans = 0;
    for (j = 0;j < size;j += 3) {
      scanf ("%d%d%d",&dp[j].x,&dp[j].y,&dp[j].z);
      dp[j+1].x = dp[j].y;
      dp[j+1].y = dp[j].z;
      dp[j+1].z = dp[j].x;
      dp[j+2].x = dp[j].z;
      dp[j+2].y = dp[j].x;
      dp[j+2].z = dp[j].y;
      dp[j].len = 0;
      dp[j+1].len = 0;
      dp[j+2].len = 0;
    }
    for (j = 0;j < size;j++) {
      dps(j);
      ans = dp[j].len > ans ? dp[j].len : ans;
    }
    printf ("Case %d: maximum height = %d\n",++step,ans);
  }
  return 0;
}
