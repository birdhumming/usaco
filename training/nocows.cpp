/*
ID: drayale1
LANG: C++
TASK: nocows
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 210, K = 110, mod = 9901;

int n, k;
int f[N][K];

int main() {
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= k; i++) f[1][i] = 1;

    for (int i = 2; i <= n; i ++) // number of cows
        for (int j = 1; j <= k; j++) // height
            for (int x = 1; x <= i - 2; x ++) { // number of cows in left subtree
                f[i][j] += (f[x][j - 1] * f[i - x - 1][j - 1]) % mod;
                f[i][j] %= mod;
            }
    
    cout << (f[n][k] - f[n][k - 1] + mod) % mod << endl;  // to get number of trees with height of exactly k
}