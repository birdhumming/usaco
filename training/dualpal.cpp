/*
ID: drayale1
LANG: C++
TASK: dualpal
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char get(int x) {
    if (x <= 9) return x + '0';
    return x - 10 + 'A';
}

string base(int n, int b) {
    string res;
    while (n) {
        res += get(n % b);
        n /= b;
    }

    reverse(res.begin(), res.end());
    return res;
}

bool check(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        if (s[i] != s[j]) return false;

    return true;
}

int main() {
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    int n, s; cin >> n >> s;

    for (int i = s + 1; n; i++) {
        int cnt = 0;
        for (int b = 2; b <= 10 && cnt < 2; b++)
            if (check(base(i, b)))
                cnt++;
        if (cnt == 2) {
            cout << i;
            if (n != 0) cout << endl;
            n--;
        }
    }

    return 0;
}