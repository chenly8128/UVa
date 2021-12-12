#include<cstdio>
#include<cstring>
using namespace std;
const int inf = 100000000;
const int maxn = 17;
int a[maxn][maxn];
int b[maxn][maxn];
int n;
int min (int a,int b) {
	return (a > b) ? b : a;
}
int check(int x){
    memset(b,0,sizeof(b));
    for(int i = 0;i < n;i++){
        if(x & 1) b[0][i] = 1;
        else if(a[0][i] == 1) return inf;
        x >>= 1;
    }
    for(int i = 1;i < n;i++)
        for(int j = 0;j < n;j++) {
            int sum = 0;
            if(i - 2 >= 0) sum += b[i-2][j];
            if(j - 1 >= 0) sum += b[i-1][j-1];
            if(j + 1 < n) sum+=b[i-1][j+1];
            sum %= 2;
            if(sum == 0 && a[i][j] == 1) return inf;
            b[i][j] = sum;
        }
    int sum = 0;
    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) if(a[i][j] != b[i][j]) sum++;
    return sum;
}
int main(void) {
    int t;
    scanf("%d",&t);
    for(int kase = 1;kase <= t;kase++) {
        scanf("%d",&n);
        int ans = inf;
        for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) scanf("%d",&a[i][j]);
        int num = 1 << n;
        for(int i = 0;i < num;i++) ans = min(ans,check(i));
        printf("Case %d: ",kase);
        printf("%d\n", (ans == inf) ? -1 : ans);
    }
    return 0;
}
