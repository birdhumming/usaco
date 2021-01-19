/*
ID: drayale1
LANG: C++
TASK: fracdec
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
int n, d, p[N];

int main() {
    memset(p, -1, sizeof p);
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
    cin >> n >> d;
    string res = to_string(n / d) + '.';
    n %= d;
    if (!n) res += '0';
    else {
        string num;
        while (n && p[n] == -1) {
            p[n] = num.size();
            n *= 10;
            num += n / d + '0';
            n %= d;
        }
        if (!n) res += num;
        else res += num.substr(0, p[n]) + '(' + num.substr(p[n]) + ')';
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if ((i + 1) % 76 == 0) cout << endl;
    }
    cout << endl;
    return 0;
}