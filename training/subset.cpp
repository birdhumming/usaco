/*
ID: drayale1
LANG: C++
TASK: subset
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 400;
int n, m;
ll f[N];

int main() {
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);

    cin >> n;
    int m = n * (n + 1) / 2;

    if (m % 2) {
        cout << 0 << endl;
        return 0;
    }

    m /= 2;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= i; j--)
            f[j] += f[j - i];
    cout << f[m] / 2 << endl;
}