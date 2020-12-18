#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vii vector<ii>
#define pb push_back
#define rz resize
#define mp make_pair
#define ff first
#define ss second

#define FOR(n) for (int i = 0; i < n; i++)
#define FOR1(n) for (int i = 1; i <= n; i++)
#define RFOR(n) for (int i = n - 1; i >= 0; i--)
#define DFOR(n, m) FOR(n) for (int j = 0; j < m; j++)

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int ddy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

bool in_bounds(int x, int y, int n, int m) {
    if (x >= 0 && x < n && y >= 0 && y < m) return true;
    return false;
}

const int N = 110;
int n, p[N];

bool is_sorted() {
    for (int i = 1; i < n; i++) 
        if (p[i] > p[i + 1]) return false;
    return true;
}

void insert(int x, int pos) {
    for (int i = 2; i <= pos; i++) p[i - 1] = p[i];
    p[pos] = x;
}

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];

    int ans = 0;
    while (!is_sorted()) {
        //for (int i = 1; i <= n; i++) cout << p[i] << " ";
        //cout << endl;
        int start;
        for (start = n; start >= 1; start--)
            if (p[start] < p[start - 1]) break;
        //cout << "start = "<<start<<endl;
        int pos = start;
        while (pos <= n && p[1] > p[pos]) pos++;
        insert(p[1], pos - 1);
        //cout << "pos - 1 = "<<pos - 1<<endl;
        ans++;
    }

    cout << ans << endl;

    return 0;
}