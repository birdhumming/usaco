/*
ID: drayale1
LANG: C++
TASK: skidesign
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010;
int n;
int h[N];

int main() {
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];

    //simulate all intervals
    //(0, 17), (1, 18), ..., (83, 100)
    int res = 1e8;
    for (int i = 0; i <= 83; i++) {
        int j = i + 17, cost = 0;
        for (int k = 0; k < n; k++)
            if (h[k] > j) cost += (h[k] - j) * (h[k] - j);
            else if (h[k] < i) cost += (i - h[k]) * (i - h[k]);
        res = min(res, cost);
    }

    cout << res << endl;

    return 0;
}