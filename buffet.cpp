#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vii vector<ii>
#define pb push_back
#define rz resize
#define mp make_pair
#define ff first
#define ss second

#define FOR(n) for (int i = 0; i < n; i++)
#define FOR1(n) for (int i = 1; i <= n; i++)
#define RFOR(n) for (int i = n - 1; i >= 0; i--)
#define DFOR(n, m) FOR(n) for (int j = 0; j < m; j++)

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int ddy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

bool in_bounds(int x, int y, int n, int m) {
    if (x >= 0 && x < n && y >= 0 && y < m) return true;
    return false;
}

const int N = 1e5 + 10;
int n, E;
int head[1010], idx;
bool visited[1010];
int dist[1010][1010], dp[1010];

struct newtt {
    int num,w;
} nodes[1010];

bool cmp(newtt a,newtt b) {
    return a.w < b.w;
}

struct newt {
    int to, next, cost;
} e[N];

void addedge (int u, int v, int w)
{
    e[idx].to = v;
    e[idx].next = head[u];
    e[idx].cost = w;
    head[u] = idx++;
}

void spfa(int u)
{
    for (int i = 1;i <= n; i++) {
        dist[u][i] = 0x3f3f3f3f;
        visited[i] = false;
    }

    queue<int> q;
    q.push(u);
    visited[u] = true;
    dist[u][u] = 0;

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        visited[now] = false;

        for (int i = head[now];i != -1; i = e[i].next)
        {
            int v = e[i].to;
            if (dist[u][v] > dist[u][now] + e[i].cost)
            {
                dist[u][v] = dist[u][now] + e[i].cost;
                if (visited[v])continue;
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    //freopen("buffet.in", "r", stdin);
    //freopen("buffet.out", "w", stdout);
    scanf("%d%d",&n, &E);
    memset(head, -1, sizeof head);

    for(int i = 1, m; i <= n; i++)
    {
        scanf("%d", &nodes[i].w);
        dp[i] = nodes[i].w;
        nodes[i].num = i;

        scanf("%d", &m);
        for(int j = 1, x; j <= m; j++)
        scanf("%d", &x), addedge(i, x, E);
    }

    sort(nodes + 1, nodes + n + 1, cmp);
    for(int i = 1;i <= n; i++) spfa(i);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            int u = nodes[i].num, v=nodes[j].num;
            dp[u] = max(dp[u], dp[v] - dist[v][u] + nodes[i].w);
        }
        ans = max(ans, dp[nodes[i].num]);
    }
    cout << ans << endl;
    return 0;
}