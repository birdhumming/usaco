#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vii vector<ii>
#define pb push_back
#define rz resize
#define mp make_pair
#define ff first
#define ss second

#define FOR(n) for (int i = 0; i < n; i++)
#define FOR1(n) for (int i = 1; i <= n; i++)
#define RFOR(n) for (int i = n - 1; i >= 0; i--)
#define DFOR(n, m) FOR(n) for (int j = 0; j < m; j++)

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int ddy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

const int MAX = 101;
int grid[MAX][MAX];
int N, K, R;
bool visited[MAX][MAX];
set<pair<ii, ii> > roads;


bool valid(int oldX, int oldY, int newX, int newY) {
    return roads.find(make_pair(make_pair(oldX, oldY), make_pair(newX, newY))) == roads.end();
}

void floodfill(int r, int c, int color) {
    if (r < 1 || r > N|| c < 1 || c > N || visited[r][c]) {
        return;
    }

    visited[r][c] = true;
    grid[r][c] = color;

    for (int i = 0; i < 4; i++) {
        int newX = r + dx[i];
        int newY = c + dy[i];
        if (valid(r, c, newX, newY)) {
            floodfill(newX, newY, color);
        }
    }
}

int main() {
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);

    cin >> N >> K >> R;

    for (int i = 0; i < R; i++) {
        int X1, Y1, X2, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;

        roads.insert(make_pair(make_pair(X1,Y1), make_pair(X2, Y2)));
        roads.insert(make_pair(make_pair(X2,Y2), make_pair(X1, Y1)));
    }

    vector<pair<int, int> > cows(K);

    for (int i = 0; i < K; i++) {
        cin >> cows[i].ff >> cows[i].ss;
    }

    int colors = 0;
    for (int i = 0; i < K; i++) {
        if (! visited[cows[i].ff][cows[i].ss]) {
            colors++;
            floodfill(cows[i].ff, cows[i].ss, colors);
        }
    }

    int ans = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < i; j++) {
            if (grid[cows[i].ff][cows[i].ss] != grid[cows[j].ff][cows[j].ss]) {
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}