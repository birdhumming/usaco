/*
ID: drayale1
LANG: C++
TASK: comehome
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cctype>
#include <unordered_set>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

const int N = 60;
int p, Z = 'Z' - 65;
int n;
unordered_set<char> cows;
unordered_set<int> pastures;
int g[N][N], dist[N];
bool st[N];

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[Z] = 0;
    //st[Z] = true;

    for (int i = 0; i < n; i++) {
        //cout << "i " << i << endl;
        int t = -1;
        for (int j : pastures)
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        
        //cout << "t = " << t << endl;
        st[t] = true;
        for (int j : pastures)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
}


int main() {
    memset(g, 0x3f, sizeof g);
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);
    cin >> p;
    while (p--) {
        char a, b; int d;
        cin >> a >>b>> d;
        if (isupper(a)) cows.insert(a);
        if (isupper(b)) cows.insert(b);
        //if (a == b) continue;
        //cout << "a = " << a << ", b = " << b << endl;
        int x = a - 65, y = b - 65;
        //cout << "x = " << x << ", y = " << y << endl;
        g[x][y] = min(g[x][y], d);
        g[y][x] = min(g[y][x], d);
        //cout << "g[x][y[ = " << g[x][y] << endl;

        pastures.insert(x);
        pastures.insert(y);
    }   

    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }*/


    n = pastures.size();
    dijkstra();

  //for (int i = 0; i < N; i++) cout << dist[i] << endl;
    int ans = 0x3f3f3f3f;
    char t;
    for (char c : cows) {
        int y = c - 65;
        if (c != 'Z' && dist[y] < ans) {
            ans = dist[y];
            t = c;
        }
    }

    cout << t << " " << ans << endl;
}