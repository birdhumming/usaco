#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

unordered_map<char, int> dir;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string solve(string s) {
    int n = s.size();
    vector<ii> v;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int nx = x + dx[dir[s[i]]];
        int ny = y + dy[dir[s[i]]];
        if (s[i] != s[(i + 1) % n]) v.push_back(make_pair(nx, ny));
        x = nx, y = ny;
    }

    //for (ii x : v) cout << x.first << " " << x.second << endl;

    int m = v.size();
    int area = 0;
    for (int i = 0; i < m; i++) {
        int j = (i + 1) % m;
        area += (v[j].first - v[i].first) * (v[j].second + v[i].second);
    }
    if (area > 0) return "CCW";
    return "CW";
}

int main() {
    int n; cin >> n;
    dir['N'] = 0;
    dir['E'] = 1;
    dir['S'] = 2;
    dir['W'] = 3;
    while (n--) {
        string s; cin >> s;
        cout << solve(s) << endl;
    }
}