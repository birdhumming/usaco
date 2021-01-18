/*
ID: drayale1
LANG: C++
TASK: money
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int N = 10010;
int v, n;
ll f[26][N];
bool visited[N];
vector<int> coins;

int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    cin >> v >> n;
    coins.push_back(0);
    for (int i = 0; i < v; i++) {
        int c; cin >> c;
        if (visited[c] || c > n) continue;
        coins.push_back(c);
        visited[c] = true;
    }
    memset(f, 0, sizeof f);
    f[0][0] = 1;

    v = coins.size() - 1;
    for (int i = 1; i <= v; i++) {
        f[i][0] = 1;
        f[i][coins[i]] = 1;
    }

    for (int i = 1; i <= v; i++)
        for (int j = 0; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= coins[i]) f[i][j] += f[i][j - coins[i]];
        }
    
    /*for (int i = 1; i <= v; i++) {
        for (int j = 0; j <= n; j++)
            cout << f[i][j] << " ";
        cout << endl;
    }*/
    cout << f[v][n] << endl;


}