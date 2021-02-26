#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2 * 1e5 + 10;
int n, a[N];
string s;

int main() {
    int t; cin >> t;
    while (t--) {
        ll x, y; cin >> x >> y;
        ll base, ans;
        if (x % 2 == 0) { //even
            base = x * x;
            if (y <= x) ans = base - y + 1;
            else {
                
            }
        }
        else { //odd
            base = (x - 1) * (x - 1) + 1;
            if (y <= x) ans = base + y - 1;

        }


    }
}