#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

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
#define RFOR(n) for (int i = n - 1; i >= 0; i--)
#define DFOR(n, m) FOR(n) for (int j = 0; j < m; j++)

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int ddy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

const int N = 62510;
int n;
int _id = 0;
int b[260][260], backup[260][260], size[260][260], id[260][260];
unordered_map<int, ii> data;
unordered_map<int, vector<int> > adj;
bool visited[N];

int dfs2(int cur_id, int c1, int c2);

//simple dfs, finds size of unit (all numbers = c)
int dfs(int x, int y, int c) {
    if (x < 0 || x >= n || y < 0 || y >= n || backup[x][y] != c) 
        return 0;
    
    backup[x][y] = -1;

    int size = 1;
    FOR(4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        size += dfs(nx, ny, c);
    }

    return size;
}

//for every (i, j) that makes up a unit of size s on the board, set size[i][j] = s
void fill_size(int x, int y, int c, int s) {
    //cout <<"x = "<<x<<", y = "<<y<<", c = "<<c<<", s = "<<s<<endl;
    if (x < 0 || x >= n || y < 0 || y >= n || b[x][y] != c || size[x][y] == s) 
        return;
    
    size[x][y] = s;

    FOR(4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        fill_size(nx, ny, c, s);
    }
}

//for every cell (i, j) in a unit, set id[i][j] to a unique _id
//may have multiple different units with same c number
//filling each with unique number prevents collision when making second graph
void dfs_id(int x, int y, int c, int _id) {
    //cout <<"x = "<<x<<", y = "<<y<<", c = "<<c<<", _id = "<<_id<<endl;
    if (x < 0 || x >= n || y < 0 || y >= n || backup[x][y] != c) 
        return;
    
    id[x][y] = _id;
    backup[x][y] = -1;

    FOR(4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs_id(nx, ny, c, _id);
    }
}

int dfs1(int cur_id, int c1, int c2) {
    if (data[cur_id].first != c1) return 0;

    int size = data[cur_id].second;
    visited[cur_id] = true;

    FOR(adj[cur_id].size()) {
        int j = adj[cur_id][i];
        if (!visited[j]) {
            size += dfs2(j, c1, c2);
        }
    }

    return size;
}

int dfs2(int cur_id, int c1, int c2) {
    if (data[cur_id].first != c2) return 0;

    int size = data[cur_id].second;
    visited[cur_id] = true;

    FOR(adj[cur_id].size()) {
        int j = adj[cur_id][i];
        if (!visited[j]) {
            size += dfs1(j, c1, c2);
        }
    }
    
    return size;
}

int main() {
    freopen("multimoo.in", "r", stdin);
    freopen("multimoo.out", "w", stdout);
    scanf("%d", &n);
    DFOR(n, n) {
        scanf("%d", &b[i][j]);
        backup[i][j] = b[i][j];
    }
    //cout<<"121\n";
    //find largest region claimed by single cow
    int ans1 = 0;
    DFOR(n, n) {
        if (backup[i][j] != -1) {
            int c = backup[i][j];
            int x = dfs(i, j, backup[i][j]);
            ans1 = max(ans1, x);

            //set size
            fill_size(i, j, c, x);
        }
    }

    DFOR(n, n) backup[i][j] = b[i][j];
    //cout<<"136\n";
    //set id[][]
    DFOR(n, n) {
        if (backup[i][j] != -1) {
            dfs_id(i, j, backup[i][j], _id);
            _id++;
        }
    }

    //data[id] = {original cow number, size of unit}
    DFOR(n, n) data[id[i][j]] = mp(b[i][j], size[i][j]);

    /*FOR(n) {
        for (int j = 0; j < n; j++) {
            cout<<id[i][j]<<' ';
        }
        cout<<endl;
    }*/
    //cout<<"154\n";
    DFOR(n, n) {
        int x = b[i][j];
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && b[nx][ny] != x) {
                adj[id[i][j]].pb(id[nx][ny]);
            }
        }
    }

    int ans2 = 0;
    FOR(_id) {
        //cout<<"i = "<<i<<endl;
        for (int j = 0; j < adj[i].size(); j++) {
            int x = dfs1(i, data[i].first, data[adj[i][j]].first);

            ans2 = max(ans2, x);

            bool flag = true;
            for (int k = 0; k < _id; k++) {
                if (!visited[k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout<<ans1<<endl;
                cout<<ans2<<endl;
                return 0;
            }
            memset(visited, false, sizeof visited);
        }
    }

    cout << ans1 << endl;
    cout<<ans2<<endl;
    return 0;
}