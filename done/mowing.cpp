#include <iostream>
#include <cstring>
using namespace std;

const int N = 2010;
int n, g[N][N];

int dx[26], dy[26];

void init() {
    dx['N' - 'A'] = 0;
    dy['N' - 'A'] = 1;
    dx['S' - 'A'] = 0;
    dy['S' - 'A'] = -1;
    dx['E' - 'A'] = 1;
    dy['E' - 'A'] = 0;
    dx['W' - 'A'] = -1;
    dy['W' - 'A'] = 0;
    memset(g, -1, sizeof g);
}

int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    cin >> n;
    init();
    int x = 1005, y = 1005;
    int ans = 0x3f3f3f3f, t = 0;
    while (n--) {
        char dir; int s; cin >> dir >> s; 
        //cout << "dir = "<<dir<<", s= "<<s<<endl;
        while (s--) {
            x += dx[dir - 'A'];
            y += dy[dir - 'A'];
            if (g[x][y] != -1) ans = min(t - g[x][y], ans);
            g[x][y] = t++;
            //cout << "x = "<<x<<", y = "<<y<<endl;
        }
    }
    
    if (ans == 0x3f3f3f3f) cout << -1 << endl;
    else cout << ans << endl;
}
