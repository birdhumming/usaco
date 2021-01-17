/*
ID: drayale1
LANG: C++
TASK: hamming
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n, b, d;

int hamming(int a, int b) {
    int d = 0;
    while (a || b) {
        if ((a & 1) != (b & 1)) d++;
        a >>= 1;
        b >>= 1;
    }
    return d;
}

int main() {
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    cin >> n >> b >> d;
    vector<int> res;

    int last = 0;
    res.push_back(last);

    //cout << hamming(0, 127) << endl;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 1 << b; j++) {
            //cout << "j = " << j << endl;
            bool flag = true;
            for (int k : res) {
                if (hamming(j, k) < d) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                //cout << "j = " << j << endl;
                res.push_back(j);
                break;
            }

            if (res.size() == n) break;
        }
    }   

    //for (int x : res) cout << x << endl;

    for (int i = 0; i < n; i += 10) {
        for (int j = i; j < n && j < i + 10; j++) {
            if (j == i) cout << res[j];
            else cout << " " << res[j];
        }
        cout << endl;
    }
}