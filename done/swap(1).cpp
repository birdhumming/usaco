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
int n, m, k;
int p[N], le[N], ri[N], ans[N];

void swap_once() {
    FOR1(n) p[i] = i;
    FOR(m) {
        int l = le[i], r = ri[i];
        int len = l + r;
        for (int j = l; j < len / 2 + 1; j++)
            swap(p[j], p[len - j]);
    }
}

void find() {
    int track[N];
    FOR1(n) {
        if (!ans[i]) {
            int cur = p[i];
            track[0] = i;
            int cnt = 1;
            
            while (i != cur) {
                track[cnt++] = cur;
                cur = p[cur];
            }

            int r = k % cnt;
            for (int j = 0; j < cnt; j++) 
                ans[track[j]] = track[(j + r) % cnt];
        }
    }
}

int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    FOR(m) scanf("%d%d", &le[i], &ri[i]);

    swap_once();
    find();
    FOR1(n) cout<<ans[i]<<endl;
    return 0;
}