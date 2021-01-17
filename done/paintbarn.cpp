#include <iostream>
using namespace std;

const int N = 1010;
int n, k;
int pref[N][N];

int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1, y1 += 1;
        x2 += 1, y2 += 1;

        pref[x1][y1] += 1;
        pref[x2][y2] += 1;
        pref[x1][y2] -= 1;
        pref[x2][y1] -= 1;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            pref[i][j] += (pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1]);
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (pref[i][j] == k) ans++;
        }
    }

    cout << ans << endl;
}