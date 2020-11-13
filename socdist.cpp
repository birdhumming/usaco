#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ii pair<int, int>
#define ll long long
#define ull unsigned ll
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

int n, m;
vector<pair<ull, ull> > intervals;

bool works(ull d) {
    int cows = 0;
    ull last = -2 * 1e18;
    FOR(m) {
        ull a = intervals[i].f, b = intervals[i].s;
        while (max(last + d, a) <= b) {
            last = max(last + d, a);
            cows++;
            if (cows >= n) break;
        }
        if (cows >= n) break;
    }
    return cows >= n;
}

int main() {
    //freopen("socdist.in", "r", stdin);
    //freopen("socdist.out", "w", stdout);
    scanf("%d%d", &n, &m); intervals.rz(m);
    FOR(m) {
        cin >> intervals[i].f >> intervals[i].s;
    }

    sort(intervals.begin(), intervals.end());

    ull l = 1, r = intervals[m - 1].s;
    //cout<<"l = "<<l<<", r = "<<r<<endl;
    int ans = 0;
    while (l <= r) {
        cout<<"l = "<<l<<", r = "<<r<<endl;
        ull mid = (l + r) >> 1;
        cout<<"mid = "<<mid<<endl;
        if (works(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout<<ans<<endl;
    return 0;
}