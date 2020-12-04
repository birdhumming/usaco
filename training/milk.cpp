/*
ID: drayale1
LANG: C++
TASK: milk
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 5010;
int n, m;
struct Milk {
    int p, a; //price, amount
    bool operator< (const Milk& t) const {
        return p < t.p;
    }
} milk[N];

int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> milk[i].p >> milk[i].a;
    sort(milk, milk + m);

    int res = 0;
    for (int i = 0; i < m && n; i++) {
        int cur = min(n, milk[i].a);
        n -= cur;
        res += cur * milk[i].p;
    }

    cout << res << endl;

    return 0;
}