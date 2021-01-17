/*
ID: drayale1
LANG: C++
TASK: holstein
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 15, M = 25;
int m, n;
int need[M], s[N][M], sum[M];

int main() {
    //freopen("holstein.in", "r", stdin);
    //freopen("holstein.out", "w", stdout);
    cin >> m;
    for (int i = 0; i < m; i++) cin >> need[i];
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m ;j++)
            cin >> s[i][j];
    
    vector<int> res;

    for (int i = 0; i < 1 << n; i++) {
        vector<int> tmp;
        memset(sum, 0, sizeof sum);
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                tmp.push_back(j);
                for (int k = 0; k < m; k++)
                    sum[k] += s[j][k];
            }
        }

        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (sum[j] < need[j]) {
                flag = false;
                break;
            }
        }

        if (flag) 
            if (res.empty() || res.size() > tmp.size() || (res.size() == tmp.size() && res > tmp)) 
                res = tmp;
    }

    cout << res.size();
    for (int x : res) cout << " " << x + 1;
    cout << endl;
}