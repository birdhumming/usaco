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

int n;
string names[8] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue" };
vector<pair<string, string> > req;

bool check() {
    string temp[10];
    temp[0] = " ";
    temp[9] = " ";
    for (int i = 1; i <= 8; i++) {
        temp[i] = names[i - 1];
    }

    for (auto t : req) {
        string a = t.ff, b = t.ss;
        for (int i = 1; i <= 8; i++) {
            if (temp[i] == a) {
                if (temp[i + 1] != b && temp[i - 1] != b) return false;
                //spent hour debugging
                //wrote "names" instead of "temp"
            }
        }
    }

    return true;
}

int main() {

    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    cin >> n;

    for (int i = 0; i < n; i++) {
        char a[10], b[10];
        scanf("%s must be milked beside %s\n", a, b);
        string _a, _b; _a = a, _b = b;
        req.pb(mp(_a, _b));
    }

    /*for (int i = 0; i < n; i++) {
        string a, b;
        string c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        //cout << a << " " << f << endl;
        req.pb(mp(a, f));
    }*/


    do {
        if (check()) {
            for (int i = 0; i < 8; i++) cout << names[i] << endl;
            break;
        }
        
    } while (next_permutation(names, names + 8));

    return 0;
}