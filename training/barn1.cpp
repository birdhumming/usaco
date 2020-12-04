/*
ID: drayale1
LANG: C++
TASK: barn1
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 210;
int m, s, c;
int a[N], b[N];

int main() {
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    cin >> m >> s >> c;
    for (int i = 0; i < c; i++) cin >> a[i];
    sort(a, a + c);

    int res = a[c - 1] - a[0] + 1;
    for (int i = 1; i < c; i++) b[i] = a[i] - a[i - 1] - 1;
    sort(b + 1, b + c, greater<int>());

    for (int i = 1; i <= m - 1 && i < c; i++) {
        res -= b[i];
    }

    cout << res << endl;

    return 0;
}