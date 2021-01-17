#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

const int N = 55;
int n, m;
char g[N][N];
bool visited[N][N];

int main() {
    freopen("gravity.in", "r", stdin);
    freopen("gravity.out", "w", stdout);
    cin >> n >> m;

    ii C, D;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            g[i][j] = c;
            if (c == 'C') C.first = i, C.second = j;
            if (c == 'D') D.first = i, D.second = j;
        }
    
    queue<pair<ii, int> > q;
    q.push(make_pair(C, 0));
    visited[C.first][C.second] = true;

    while (q.size()) {
        ii t = q.front().first;
        int x = t.first, y = t.second;
        int flips = q.front().second;
        q.pop();

        //cout << "x = " << x << ", y = " << y << ", flips = " << flips << endl;

        if (t == D) {
            cout << flips << endl;
            return 0;
        }

        //move right
        int ny = y + 1, nx = -1;
        if (flips % 2) { //gravity up
            for (int i = x; i >= 0; i--) {
                //cout << "i = " << i << endl;
                if (g[i][ny] == '#') {
                    nx = i + 1;
                    break;
                }
            }
        }
        else {
            for (int i = x; i < n; i++) {
                if (g[i][ny] == '#') {
                    nx = i - 1;
                    break;
                }
            }
        }
        //cout << "nx = " << nx << endl;
        if (x >= 0 && x < n && ny >= 0 && ny < n && g[x][ny] != '#' && !visited[x][ny] && nx != -1) {
            visited[x][ny] = true;
            q.push(make_pair(make_pair(x, ny), flips));
        }

        ///move left
        nx = -1;
        if (flips % 2) { //gravity up
            for (int i = x; i >= 0; i--) {
                if (g[i][ny] == '#') {
                    nx = i + 1;
                    break;
                }
            }
        }
        else {
            for (int i = x; i < n; i++) {
                if (g[i][ny] == '#') {
                    nx = i - 1;
                    break;
                }
            }
        }
        ny = y - 1;
        if (x >= 0 && x < n && ny >= 0 && ny < n && g[x][ny] != '#' && !visited[x][ny] && nx != -1) {
            visited[x][ny] = true;
            q.push(make_pair(make_pair(x, ny), flips));
        }

        //fall down
        nx = -1;
        for (int i = x; i < n; i++) {
            if (g[i][y] == '#') {
                nx = i - 1;
                break;
            }
        }
        if (nx != -1 && !visited[nx][y]) {
            if (flips % 2) { //gravity = up
                q.push(make_pair(make_pair(nx, y), flips + 1));
            }
            else { //gravity = down
                q.push(make_pair(make_pair(nx, y), flips));
            }
            visited[nx][y] = true;
        }

        //fall up
        nx = -1;
        for (int i = x; i >= 0; i--) {
            if (g[i][y] == '#') {
                nx = i + 1;
                break;
            }
        }
        if (nx != -1 && !visited[nx][y]) {
            if (flips % 2) { //gravity = up
                q.push(make_pair(make_pair(nx, y), flips));
            }
            else { //gravity = down
                q.push(make_pair(make_pair(nx, y), flips + 1));
            }
            visited[nx][y] = true;
        }
    }

    cout << -1 << endl;
}