#include <iostream>
using namespace std;

const int N = 1010;
int n, g[N][N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    int a1 = 0;
    for (int i = 0; i < n; i++) {
        int s1 = 0, s2 = 0; //s1 sum including g[i][0], s2 sum including s[i][1]
        for (int j = 0; j < n; j++) {
            if (j % 2) s2 += g[i][j];
            else s1 += g[i][j];
        }
        a1 += max(s1, s2);
    }

    int a2 = 0;
    for (int j = 0; j < n; j++) {
        int s1 = 0, s2 = 0; //s1 sum including g[0][j], s2 sum including g[1][j]
        for (int i = 0; i < n; i++) {
            if (i % 2) s2 += g[i][j];
            else s1 += g[i][j];
        }
        a2 += max(s1, s2);
    }

    cout << max(a1, a2) << endl;
}