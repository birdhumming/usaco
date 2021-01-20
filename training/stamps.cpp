/*
ID: drayale1
LANG: C++
TASK: stamps
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 55, M = 2 * 1e6 + 10;
int k, n, s[N], f[M];

int main() {
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);
    cin >> k >> n;
    int max_val = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        max_val = max(max_val, s[i]);
    }

    max_val *= k;

    for (int i = 1; i <= n; i++)
        for (int j = s[i]; j <= max_val; j++) {
            f[j] = min(f[j], f[j - s[i]] + 1);
        }

    for (int i = 0; i < M; i++) {
        if (f[i] > k) {
            cout << i - 1 << endl;
            return 0;
        }
    }
}