#include <iostream>
using namespace std;

typedef long long ll;
ll n, k, m;

bool check(ll x) {
    ll days = 0, given = 0;
    while (given < n) {
        ll y = (n - given) / x;
        if (y < m) {
            ll left = (n - given + m - 1) / m;
            return left <= k;
        }
        given += y;
        days++;


        if (days > k) return false;
    }

    return days <= k;
}

int main() {
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    cin >> n >> k >> m;

    ll l = 1, r = n;
    while (l < r) {
        ll mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    cout << r << endl;
}