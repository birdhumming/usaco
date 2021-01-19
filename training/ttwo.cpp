/*
ID: drayale1
LANG: C++
TASK: ttwo
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

ii c, f;
char g[10][10];
int c_visited[10][10], g_visited[10][10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


int main() {
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'C') c.first = i, c.second = j;
            else if (g[i][j] == 'F') f.first = i, f.second = j;
        }

    ii of = f;
    ii oc = c;
    
    int t = 0;
    int cd = 0, fd = 0;

    for (int i = 0; i < 1e7; i++) {
        t++;
        int cx = c.first + dx[cd];
        int cy = c.second + dy[cd];
        if (cx < 0 || cx >= 10 || cy < 0 || cy >= 10 || g[cx][cy] == '*') {
            cd++;
            cd %= 4;
        }
        else c = make_pair(cx, cy);
        
        int fx = f.first + dx[fd];
        int fy = f.second + dy[fd];
        if (fx < 0 || fx >= 10 || fy < 0 || fy >= 10 || g[fx][fy] == '*') {
            fd++;
            fd %= 4;
        }
        else f = make_pair(fx, fy);

        if (c == f) {
            cout << t << endl;
            return 0;
        }
    }

    cout << 0 << endl;
}