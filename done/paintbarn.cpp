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
#define f first
#define s second

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

int n, k;
int g[1010][1010];
int pref[1010][1010];

int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int n, k; scanf("%d%d", &n, &k);
    //cout<<"n = "<<n<<", k = "<<k<<endl;
    FOR(n) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1++, y1++, x2 ++, y2++;
        g[x1][y1]++;
        g[x2][y2]++;
        g[x1][y2]--;
        g[x2][y1]--;
    }
    
    int ans = 0;
    for (int i = 1; i < 1010; i++) {
        for (int j = 1; j < 1010; j++) {
            //cout<<g[i][j]<<endl;
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + g[i][j];
            if (pref[i][j] == k) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}