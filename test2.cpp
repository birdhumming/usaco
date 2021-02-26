#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> ii;

const int N = 1010;
int n, g[N][N];
bool cows[N][N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        cows[x][y] = true;

        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx >= 0 && nx <= 1000 && ny >= 0 && ny <= 1000) {
                g[nx][ny]++;
                if (cows[nx][ny] && g[nx][ny] == 3) ans++;
                if (cows[nx][ny] && g[nx][ny] == 4) ans--;
            }
        }

        if (g[x][y] == 3) ans++;

        cout << ans << endl;
    }
}