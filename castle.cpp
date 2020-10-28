#include <iostream>
using namespace std;
typedef pair<int, int> ii;

const int N = 60;
int g[N][N], h[N][N];
int m, n;
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

int dfs(int x, int y) {
    //cout<<x<<' '<<y<<endl;
    if (g[x][y] == -1) return 0;
    if (x < 0 || x >= n || y < 0 || y > m) return 0;

    int room = g[x][y];
    g[x][y] = -1;
    int size = 1;
    
    for (int i = 0; i < 4; i++) {
        if (!((room >> i) & 1)) {
            int nx = x + dx[i], ny = y + dy[i];
            size += dfs(nx, ny);
        }
    }
    h[x][y] = size;
    return size;
}

void dfs1(int x, int y, int val) {
    
}

int main() {
    //freopen("castle.in", "r", stdin);
    //freopen("castle.out", "w", stdout);

    scanf("%d%d", &m, &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            scanf("%d", &g[i][j]);
    
    int cnt = 0, largest = 1;
    
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (g[i][j] != -1) {
                cnt++;
                largest = max(largest, dfs(i, j));
            }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (h[i][j] != -1) {
                int val = h[i][j];
                dfs1(i, j, val);
            }
        }
    }
 
    cout<<"cnt = "<<cnt<<", largest = "<<largest<<endl; 
}