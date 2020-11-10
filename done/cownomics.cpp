#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define pb push_back
#define rs resize
#define mp make_pair

#define FOR(n) for (int i = 0; i < n; i++)
#define FOR1(n) for (int i = 1; i <= n; i++)

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int ddy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

int n, m;
string spot[501];
string plain[501];
bool track[334] = {false};

int str_int(char a, char b, char c) {
    int ans = 0;

    if (a == 'C') ans += 100;
    if (a == 'G') ans += 200;
    if (a == 'T') ans += 300;
    if (b == 'C') ans += 10;
    if (b == 'G') ans += 20;
    if (b == 'T') ans += 30;
    if (c == 'C') ans += 1;
    if (c == 'G') ans += 2;
    if (c == 'T') ans += 3;
    
    return ans;
}

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(n) scanf("%d", &spot[i]);
    FOR(n) scanf("%d", &plain[i]);

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                memset(track, false, sizeof track);
                ans++;

                for (int c = 0; c < n; c++) {
                    int t = str_int(spot[c][i], spot[c][j], spot[c][k]);
                    track[t] = true;
                }

                for (int c = 0; c < n; c++) {
                    int t = str_int(plain[c][i], plain[c][j], plain[c][k]);
                    if (track[t]) {
                        ans--;
                        break;
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}