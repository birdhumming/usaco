#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
vector<iii> tmp;
const int N = 1010;

int n, g[N][N];
bool visited[N][N];
int dx[4][3] = { 
    {-1, -1, 0},
    {-1, 0, -1},
    {1, 0, 1},
    {1, 1, 0}
};
int dy[4][3] = {
    {-1, 0, -1},
    {1, 1, 0},
    {-1, -1, 0},
    {1, 0, 1}
};

bool valid(int x, int y) {
    //cout << "x = " << x << ". y = " << y << endl;
    for (int i = 0; i < 4; i++) {
        bool flag = false;
        int track = 0;
        int cnt = 0;
        for (int j = 0; j < 3; j++) {
            int nx = x + dx[i][j];
            int ny = y + dy[i][j];
            //cout << "nx == " << nx <<", ny ="  << ny << endl;
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny]) cnt++, track++;
        }
        if (cnt == 2) return false;
    }
    return true;
}

int dfs(int x, int y) {
    int ans = 0;
    if (!valid(x, y)) return -1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; i++) {
            int nx = x + dx[i][j];
            int ny = y + dy[i][j];
            //cout << "nx == " << nx <<", ny ="  << ny << endl;
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            visited[nx][ny] = true;
            ans += dfs(nx, ny);
        }
    }
    return ans;
}

bool cmp(iii a, iii b) {
    if (a.first != b.first) return a.first > b.first;
    //return a.second.first < b.second.first;
}   

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            //tmp.push_back(make_pair(g[i][j], make_pair(i, j)));
        }

    sort(tmp.begin(), tmp.end(), cmp);
    int ans = 0;

    /*for (auto t : tmp) {
        int val = t.first;
        //cout << "val = " << val << endl;
        if (valid(t.second.first, t.second.second)) {
            //cout << 55 << endl;
            ans += val;
            visited[t.second.first][t.second.second] = true;
        }
        //cout << 58 << endl;
    }*/

    int ans = 0, final = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n;j++ ) {
            int res = dfs(i, j);
            if (res == -1) {
                flag = false;
                break;
            }
            ans += res;
        }
    }

    if (flag) final += ans;
    else final -= ans;

    flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int res = dfs(j, i);
            if (res == -1) {
                flag = false;
                break;
            }
            ans += res;
        }
    }
    if (flag) final += ans;
    else final -= ans;

    cout << final << endl;
       
}