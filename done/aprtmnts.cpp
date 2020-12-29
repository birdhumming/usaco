#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int N = 2 * 1e5 + 10;
int n, m, k;
int a[N], b[N];

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    int ans = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        //cout << "i = "<<i<<endl;
        int p = a[i];
        while (j < m && b[j] < p - k) j++;
        //cout << "j = "<<j<<", b[j] = "<<b[j]<<endl;
        if (p - k <= b[j] && b[j] <= p + k) {
            //cout << "a[i] = "<<a[i]<<", b[j] = "<<b[j]<<endl;
            b[j] = -1;
            ans++;
        }
    }

    cout << ans << endl;
}