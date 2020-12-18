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
int n;
vector<string> a;
set<string> chars;
unordered_map<string, vector<string> > animals;

//a intersection b
int count(vector<string>& a, vector<string>& b) {
    int ans = 0;
    for (string x : a) 
        for (string y : b) 
            if (x == y) {
                ans++;
                break;
            }
    return ans;
}


int main() {
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name; int k;
        cin >> name >> k;
        a.pb(name);
        for (int j = 0; j < k; j++) {
            string ch; cin >> ch; //characteristic
            animals[name].pb(ch);
            chars.insert(ch);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++) {
            auto x = animals[a[i]];
            auto y = animals[a[j]];
            ans = max(ans, count(x, y));
        }
    
    cout << ans + 1 << endl;
    return 0;
}