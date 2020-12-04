/*
ID: drayale1
LANG: C++
TASK: beads
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 710;
int n; char s[N];

//if blue, return 1
//if red, return 2
int get(char c) {
    if (c == 'b') return 1;
    return 2;
}

int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; i++) s[i + n] = s[i];

    int res = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = i + n - 1;
        int cnt = 0, left = 0, right = 0;
        while (l <= r && (s[l] == 'w' || (left | get(s[l])) != 3)) {
            if (s[l] != 'w') left |= get(s[l]);
            cnt++, l++;
        }

        while (l <= r && (s[r] == 'w' || (right | get(s[r])) != 3)) {
            if (s[r] != 'w') right |= get(s[r]);
            cnt++, r--;
        }

        res = max(res, cnt);
    }

    cout << res << endl;
    return 0;
}
//using binary numbers to represent color
//1 1
