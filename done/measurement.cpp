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

struct board {
    vector<string> strings;
    int milk;
    bool operator== (const board& t) {
        if (strings.size() != t.strings.size()) return false;
        for (int i = 0; i < strings.size(); i++) 
            if (strings[i] != t.strings[i]) return false;
        
        return true;
    }
};

unordered_map<string, int> cow_num;
int n;
int measurements[110][3];

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    cow_num["Bessie"] = 0;
    cow_num["Elsie"] = 1;
    cow_num["Mildred"] = 2;

    cin >> n;
    int max_day = 0;
    for (int i = 0; i < n; i++) {
        int day; cin >> day; max_day = max(day, max_day);
        string cow, change; cin >> cow >> change;
        int _change = stoi(change.substr(1));
        if (change[0] == '-') _change *= -1;

        measurements[day][cow_num[cow]] = _change;
    }

    int b = 7, e = 7, m = 7; //Bessie, Elsie, Mildred
    milk[7] = 3;
    int ans = 0;
    board cur_b;
    cur_b.strings.pb("Bessie");
    cur_b.strings.pb("Elsie");
    cur_b.strings.pb("Mildred");
    cur_b.milk = 7;

    for (int i = 1; i <= max_day; i++) {
        b += measurements[i][0];
        e += measurements[i][1];
        m += measurements[i][2];
        int temp_max = max(b, max(e, m));
        board b1;
        if (b == temp_max) b1.strings.pb("Bessie");
        if (e == temp_max) b1.strings.pb("Elsie");
        if (m == temp_max) b1.strings.pb("Mildred");
        b1.milk = temp_max;
        if (!(cur_b == b1)) ans++;
        cur_b = b1;
    }

    cout << ans << endl;
    return 0;
}

//this took me 2 days to figure out
//why