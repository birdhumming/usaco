#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int n;
int g[N][N];
char s[N];

int cal(int l, int r, int d, int u, int t)
{
    int ans = 0;
    for (int i = l; i <= r; i++)
        for(int j = d;j <= u; j++)
            ans += g[i][j] == t;
    return ans;
}

int main()
{
    freopen("leftout.in", "r", stdin);
    freopen("leftout.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++)
            g[i][j] = s[j] == 'L';
    }
    for (int i = 1; i <= n; i++) {
        if (g[1][i] == 1)
            for (int j = 1; j <= n; j++)
                g[j][i] ^= 1;
    }

    for (int i = 1; i <= n; i++) {
        if (g[i][1] == 1)
            for (int j = 1; j <= n; j++)
                g[i][j] ^= 1;
    }

    if (cal(2, n, 2, n, 0) == 0) {
        printf("1 1\n");
        return 0;
    }

    if (cal(2, n, 2, n, 1) == 1) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (g[i][j] == 1) {
                    printf("%d %d\n", i, j);
                }
    }

    else {
        if (cal(2, n, 2, n, 1) == n - 1) {
            for (int i = 2; i <= n; i++) 
                if (cal(2, n, i, i, 1) == n - 1) {
                    printf("1 %d\n", i);
                    return 0;
                }
            for (int i = 2; i <= n; i++) {
                if (cal(i, i, 2, n, 1) == n - 1) {
                    printf("%d 1\n", i);
                    return 0;
                }
            }
        }
        printf("-1\n");
        return 0;
    }
}