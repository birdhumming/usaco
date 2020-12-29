#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = 50010;
int n, k;
ll a[N];

bool check(ll x) {
    //cout << "x = "<<x<<endl;
    int used = 0;
    for (int i = 0; i < n;) {
        ll pos = a[i] + x;
        used++;
        while (i < n && abs(pos - a[i]) <= x) i++;
    }
    //cout << "used = "<<used << endl;
    return used <= k;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    ll l = 0, r = 1e9 + 10;
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << r << endl;
}

//slower than other one because of line 31
//using automatic max, other one uses input