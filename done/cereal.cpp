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

const int N = 1e5 + 10;
int n, m;
int f[N], s[N], taken[N];
int ans[N];

int main() {
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(n) scanf("%d%d", &f[i], &s[i]);

    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        int j = i;
        int pos = f[i];
        while (true) {
            if (taken[pos] == 0) {
                taken[pos] = j;
                cnt++;
                break;
            }
            else if (taken[pos] < j) break;
            else {
                int k = taken[pos];
                taken[pos] = j;
                if (pos == s[k]) break;
                j = k;
                pos = s[k];
            }
        }
        ans[i] = cnt;
    }

    FOR(n) cout<<ans[i]<<endl;
    return 0;
}