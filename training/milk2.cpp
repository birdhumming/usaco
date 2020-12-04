/*
ID: drayale1
LANG: C++
TASK: milk2
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
#define x first
#define y second

const int N = 5010;
int n; ii seg[N];

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> seg[i].x >> seg[i].y;
    sort(seg, seg + n);

    int res1 = 0, res2 = 0;
    int l = seg[0].x, r = seg[0].y;
    for (int i = 1; i < n ;i++) {
        if (seg[i].x <= r) r = max(r, seg[i].y);
        else {
            res1 = max(res1, r - l);
            res2 = max(res2, seg[i].x - r);
            l = seg[i].x, r = seg[i].y;
        }
    }

    res1 = max(res1, r - l);
    cout << res1 << " " << res2 << endl;

    return 0;
}