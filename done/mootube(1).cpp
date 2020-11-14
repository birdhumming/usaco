#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define vc vector<char>
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

const int N = 10000 + 10;
int n, q;
int h[N], w[N], e[N], ne[N], idx = 0;
bool visited[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int solve(int k, int v) {
    //cout<<"k = "<<k<<", v = "<<v<<endl;
    if (visited[v]) return 0;
    int suggested = 1;
    visited[v] = true;

    for (int i = h[v]; i != -1; i = ne[i]) {
        int rel = w[i], j = e[i];
        if (rel >= k && !visited[j]) 
            suggested += solve(k, j);
    }

    return suggested;
}

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    scanf("%d%d", &n, &q);
    memset(h, -1, sizeof h);
    FOR(n - 1) {
        int a, b, r; scanf("%d%d%d", &a, &b, &r);
        add(a, b, r); add(b, a, r);
    }

    /*FOR(n + 1) cout<<h[i]<<' ';
    cout<<endl;
    FOR(n + 1) cout<<w[i]<<' ';
    cout<<endl;
    FOR(n + 1) cout<<e[i]<<' ';
    cout<<endl;*/

    while (q--) {
        memset(visited, false, sizeof visited);
        int k, v; scanf("%d%d", &k, &v);
        cout<<solve(k, v) - 1<<endl;
    }
    return 0;
}