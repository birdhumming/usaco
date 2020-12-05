/*
ID: drayale1
LANG: C++
TASK: combo
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 3;
int n;
int a[N], b[N];

int both() {
    int res = 1;
    for (int i = 0; i < 3; i++) {
        int x = a[i], y = b[i];
        int d = min(abs(x - y), n - abs(x - y));
        res *= min(n, max(0, 5 - d));
    }
    return res;
}

int single() {
    int res = 1;
    for (int i = 0; i < 3; i++) res *= min(n, 5);
    return res;
}

int main() {
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    cin >> n; 
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) cin >> b[i];

    cout << single() + single() - both() << endl;

    return 0;
}