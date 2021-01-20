/*
ID: drayale1
LANG: C++
TASK: agrinet
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110, INF = 0x3f3f3f3f;
int n, g[N][N], dist[N];
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 0; j < n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        
        if (i && dist[t] == INF) return INF;

        if (i) res += dist[t];
        st[t] = true;

        for (int j = 0; j < n; j++) dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}

int main() {
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    cout << prim() << endl;
        
}