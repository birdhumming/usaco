#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;

const int N = 3010;
int n, m;
bool g[N][N];
//int h[N], e[N], ne[N], idx;
//int dist[N];
bool visited[N];


/*void add(int a, int b) {
    e[a] = b, ne[a] = h[a], h[a] = idx++;
}

bool dijkstra() {
    priority_queue<ii, vector<ii>, greater<ii> > heap;
    heap.push(make_pair(0, 1));

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    while (heap.size()) {
        int ver = heap.top().second;
        heap.pop();

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] + 1) {
                dist[j] = dist[ver] + 1;
                heap.push(make_pair(dist[j], j))
            }
        }
    }
}*/

void solve(int u) {
    visited[u] = true;
    for (int i = 1; i <= n; i++) {
        if (g[u][i] && !visited[i]) solve(i);
    }
}

int num_visited() {
    int res = 0;
    for (int i = 1; i <= n; i++) 
        if (visited[i]) res++;
    return res; 
}

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    scanf("%d%d", &n, &m);

    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a][b] = true; g[b][a] = true;
    }
    /*memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }*/

    int o = n;
    solve(1);
    if (num_visited() == n) puts("YES");
    else puts("NO");

    for (int i = 1; i < n; i++) {
        memset(visited, false, sizeof visited);
        int x; scanf("%d", &x);
        for (int i = 1; i <= n; i++) {
            g[x][i] = false; g[i][x] = false;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (g[i][j] == true) {
                    solve(i);
                    break;
                }
            }
        }

        if (num_visited() == n - i) puts("YES");
        else if (i == n - 1) puts("YES");
        else puts("NO");
    }

    return 0;

}
\\