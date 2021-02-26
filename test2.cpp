#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const int N = 2 * 1e5 + 10;
int n, a[N];
string s;

int solve(int k) {
    ll ans = 0;
    
    //outermost corners
    ans += 2 * (k * k - 3);

    //corner adjacent
    ans += 4 * (k * k - 4);

    //middle out - corner lines
    ans += (k * k - 5) * (2 * k - 8);

    //secondary corners
    ans += 2 * (k * k - 5);

    //secondary corners adjacent
    ans += (k * k - 7) * (2 * k - 8);

    //center - 2 off
    ll diff = (k * k - 9) * (k - 4) * (k - 4);
    ans += (diff / 2);

    //ans /= 2;

    return ans;
}

int main() {
    int n; cin >> n;
    for (int k = 1; k <= n; k++) {
        cout << solve(k) << endl;
    }
}