#include <iostream>
using namespace std;

const int N = 2010;
int n, r[N];

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> r[i];
    for (int i = n; i < 2 * n; i++) r[i] = r[i - n];

    int ans = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = i; j < i + n; j++) {
            tmp += (j - i) * r[j];
        }
        ans = min(tmp, ans);
    }

    cout << ans <<endl;
}