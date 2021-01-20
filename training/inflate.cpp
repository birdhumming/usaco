/*
ID: drayale1
LANG: C++
TASK: inflate
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

const int N = 10010;
int n, m, v[N], w[N];
int f[N];

int main() {
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    
    cout << f[m] << endl;
}