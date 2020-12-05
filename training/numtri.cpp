/*
ID: drayale1
LANG: C++
TASK: numtri
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010;
int n;
int a[N][N], f[N][N];

int main() {
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            scanf("%d", &a[i][j]);
    
    for (int i = n - 1; i >= 0; i--) 
        for (int j = 0; j <= i; j++)
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];
    
    cout << f[0][0] << endl;

    return 0;
}