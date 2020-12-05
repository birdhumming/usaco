/*
ID: drayale1
LANG: C++
TASK: sprime
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

bool is_prime(int x) {
    for (int i = 2; i <= x / 2; i++)
        if (x % i == 0)
            return false;
    return true;
}

void dfs(int x, int k) {
    if (!is_prime(x)) return;
    if (k == n) cout << x << endl;

    else {
        int d[4] = {1, 3, 7, 9};
        for (int i  : d)
            dfs(x * 10 + i, k + 1);
    }
}

int main() {
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    cin >> n;

    dfs(2, 1), dfs(3, 1), dfs(5, 1), dfs(7, 1);
    return 0;
}