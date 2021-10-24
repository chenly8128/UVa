#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main (void) {
  int n,q,step = 0;
  vector <int> marble;
  while (scanf ("%d%d",&n,&q),n != 0 || q != 0) {
    marble.clear();
    for (int j = 0;j < n;j++) {
      int a;
      scanf ("%d",&a);
      marble.push_back(a);
    }
    sort (marble.begin(),marble.end());
    printf ("CASE# %d:\n",++step);
    for (int j = 0;j < q;j++) {
      int a;
      scanf ("%d",&a);
      int p = lower_bound(marble.begin(),marble.end(),a) - marble.begin();
      if (marble[p] == a) printf ("%d found at %d\n",a,p + 1);
      else printf ("%d not found\n",a);
    }
  }
  return 0;
}
