#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;


bool comp(string u, string v) { //u short, v long
    int n = u.length();
    if (v.substr(0, n) == u) return true;
    if (v.substr(1, n) == u) return true;
    return false;
}

int solve(string t) {
    //cout << "t = " << t << endl;
    if (t.length() % 2 == 0) return 0;
    if (t.length() < 2) return 0;

    int res = 0;

    int n = t.length() / 2;
    int m = n + 1;

    string u = t.substr(0, n);
    string v = t.substr(n, m);
    if (comp(u, v)) {
        res++;
        res += solve(u);
        res += solve(v);
    }

    u = t.substr(0, m);
    v = t.substr(m, n);
    if (comp(v, u)) {
        res++;
        res += solve(u);
        res += solve(v);
    }

    return res;
}

int main() {
    //freopen("scode.in", "r", stdin);
    //freopen("scode.out", "w", stdout);
    cin >> s;

    cout << solve(s) << endl;
}