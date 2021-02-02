#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, ll> pll;

const int N = 1e5 + 10;
int n, m;
pll a[N];

bool check(int x) {
    //cout << "x = " << x << endl;
    ll last = -1e18;
    int placed = 0;
    for (int i = 0; i < m; i++) {
        ll start = a[i].first;
        ll end = a[i].second;
        //ll dist = end - start;

        if (start - last < x) start += (x - (start - last));
        if (start > end) continue;

        //cout << "start = " << start << ", edn + " << end << endl;
        ll dist = end - start;
        int p_temp = (dist / x) + 1;
        placed += p_temp;

        //cout << "placed = " << placed << endl;
        last = start + (p_temp - 1) * x;
        //cout << ";ast = " << last << endl;
    }

    return placed >= n;
}

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i].first >> a[i].second;
    sort(a, a + m);

    ll l = 0, r = 0;
    for (int i = 0; i < m; i++) r = max(r, a[i].second);

    while (l < r) {
        //cout << "l = " << l<<", r= " << r << endl;
        ll mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    cout << l << endl;
}