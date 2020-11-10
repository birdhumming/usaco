#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define pb push_back
#define all(v) v.begin(), v.end()

#define FOR(n) for (int i = 0; i < n; i++)
#define FOR1(n) for (int i = 1; i <= n; i++)

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int ddy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

int n;
vector<ii> c;

int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    scanf("%d", &n);
    FOR(n) {
        int x, y; scanf("%d%d", &x, &y);
        c.pb(ii(y, x));
    }

    sort(c.begin(), c.end());
    int ans = 0, i = 0, j = n - 1;

    while (i <= j) {
        int taken = min(c[i].second, c[j].second);
        if (i == j) taken /= 2;
        ans = max(ans, c[i].first + c[j].first);
        c[i].second -= taken;
        if (c[i].second == 0) i++;
        c[j].second -= taken;
        if (c[j].second == 0) j--;
    }

    cout << ans << endl;

    return 0;
}