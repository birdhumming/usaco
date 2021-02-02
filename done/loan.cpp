#include <iostream>
using namespace std;

typedef long long ll;
ll n, k, m;

bool check(ll x) {
    ll days_left = k, milk_left = n;
    while (milk_left >= 0) {
        //cout << "milk_left = " << milk_left << endl;
        //if (days_left < 0) return false;
        ll y = milk_left / x;
        if (y <= m) {
            return days_left * m >= milk_left;
        }

        ll len = milk_left - (x * y);
        len /= y;
        len++;

        days_left -= len;
        milk_left -= (y * len);
    }

    if (days_left >= 0) return true;
}

int main() {
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    cin >> n >> k >> m;

    ll l = 1, r = n;
    while (l < r) {
        //cout << "l = " << l <<", r = " << r << endl;
        ll mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    cout << r << endl;
}