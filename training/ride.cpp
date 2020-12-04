/*
ID: drayale1
LANG: C++
TASK: ride
*/

#include <iostream>
using namespace std;

int get(string s) {
    int res = 1;
    for (auto c : s) {
        res *= c - 'A' + 1;
        res %= 47;
    }
    return res;
}

int main() {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string a, b; cin >> a >> b;

    if (get(a) == get(b)) puts("GO");
    else puts("STAY");

    return 0;
}