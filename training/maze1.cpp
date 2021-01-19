/*
ID: drayale1
LANG: C++
TASK: maze1
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
const int N = 210, M = 80;
int h, w, g[N][M], n, m;
bool visited[N][M];
ii ex1, ex2;
bool found = false;
string str[N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dist1[N][M], dist2[N][M];

void prnt(ii a) {
    cout << a.first << " " << a.second << endl;
}

void bfs1() {
    memset(visited, false, sizeof visited);
    //cout << "x = " << x << ", y = "<<y<<endl;
    queue<iii> q;
    q.push(make_pair(ex1, 0));
    visited[ex1.first][ex1.second] = true;
    dist1[ex1.first][ex1.second] = 0;

    while (q.size()) {
        auto t = q.front();
        q.pop();

        ii c = t.first;
        int d = t.second;
        //cout << "c.first = " << c.first << ". c.second = "<<c.second<<endl;

        for (int i = 0; i < 4; i++) {
            int nx = c.first + dx[i];
            int ny = c.second + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && str[nx][ny] == ' ' && !visited[nx][ny]) {
                q.push(make_pair(make_pair(nx, ny), d + 1));
                visited[nx][ny] = true;
                dist1[nx][ny] = d + 1;
            }
        }
    }
}

void bfs2() {
    memset(visited, false, sizeof visited);
    queue<iii> q;
    q.push(make_pair(ex2, 0));
    visited[ex2.first][ex2.second] = true;
    dist2[ex2.first][ex2.second] = 0;

    while (q.size()) {
        auto t = q.front();
        q.pop();

        ii c = t.first;
        int d = t.second;
        //cout << "c.first = " << c.first << ". c.second = "<<c.second<<endl;

        for (int i = 0; i < 4; i++) {
            int nx = c.first + dx[i];
            int ny = c.second + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && str[nx][ny] == ' ' && !visited[nx][ny]) {
                q.push(make_pair(make_pair(nx, ny), d + 1));
                visited[nx][ny] = true;
                dist2[nx][ny] = d + 1;
            }
        }
    }
}


int main() {
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);
    cin >> w >> h;
    n = h * 2 + 1;
    m = w * 2 + 1;

    getchar();
    for (int i = 0; i < n; i++) getline(cin, str[i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (str[i][j] == ' ' && (i == n - 1 || i == 0 || j == 0 || j == m - 1)) {
                if (!found) ex1.first = i, ex1.second = j, found = true;
                else ex2.first = i, ex2.second = j;
            }
        }
    
    bfs1();
    bfs2();
    
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (str[i][j] == ' ') {
                int dist = min(dist1[i][j], dist2[i][j]);
                ans = max(ans, dist);
            }
    cout << (ans + 1) / 2<< endl;
}