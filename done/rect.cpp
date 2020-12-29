#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

const int N = 2510;
int n;
ii points[N];
int pref[N][N];

bool cmp(ii a, ii b) { return a.second < b.second; }

int sum(int x1, int y1, int x2, int y2) {
    return pref[x2 + 1][y2 + 1] - pref[x2 + 1][y1] - pref[x1][y2 + 1] + pref[x1][y1];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> points[i].first >> points[i].second;

    sort(points, points + n);
    for (int i = 0; i < n; i++) points[i].first = i + 1;
    sort(points, points + n, cmp);
    for (int i = 0; i < n; i++) points[i].second = i + 1;

    for (int i = 0; i < n; i++) pref[points[i].first][points[i].second] = 1;

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j <= n; j++) {
            int x1 = min(points[i].first, points[j].first) - 1;
            int x2 = max(points[i].first, points[j].first) - 1;
            ans += sum(0, i, x1, j) * sum(x2, i, n - 1, j);
        }
    }

    cout << ans + 1 << endl;
}