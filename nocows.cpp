/*
ID: drayale1
LANG: C++
TASK: nocows
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 210, M = 110, MOD = 9901;

int n, m;
int f[N][M];

int main() {
    //freopen("nocows.in", "r", stdin);
    //freopen("nocows.out", "w", stdout);
    cin >> n >> m;

    for (int i = 1; i <= m; i++) f[1][i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = m; k > i - 10; k--)
                f[i][j] = f[i - k][j - 1] + //must include subsegment removed

    cout << f[n][m] << endl;
}