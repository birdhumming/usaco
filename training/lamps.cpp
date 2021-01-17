/*
ID: drayale1
LANG: C++
TASK: lamps
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int state[8][6] = {
    {1, 1, 1, 1, 1, 1}, //none
    {0, 0, 0, 0, 0, 0}, //1
    {0, 1, 0, 1, 0, 1}, //2
    {1, 0, 1, 0, 1, 0}, //3
    {0, 1, 1, 0, 1, 1}, //4
    {1, 0, 0, 1, 0, 0}, //1 4
    {1, 1, 0, 0, 0, 1}, //2 4 
    {0, 0, 1, 1, 1, 0}, //3 4
};

int n, c;
vector<int> on, off;

bool check(int s[6]) {
    for (auto id : on)
        if (!s[id % 6])
            return false;
    for (auto id : off)
        if (s[id % 6])
            return false;
    return true;
}

void solve(vector<int> ids) {
    sort(ids.begin(), ids.end(), [](int a, int b) {
        for (int i = 0; i < 6; i++)
            if (state[a][i] != state[b][i])
                return state[a][i] < state[b][i];
        return false;
    });

    bool out = false;
    for (auto id : ids) {
        auto s = state[id];
        if (check(s)) {
            out = true;
            for (int i = 0; i < n ;i++)
                cout << s[i % 6];
            cout << endl;
        }
    }
    if (!out) cout << "IMPOSSIBLE\n";
}

int main() {
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
    cin >> n >> c;
    int x;
    while (cin >> x, x != -1) on.push_back(x - 1);
    while (cin >> x, x != -1) off.push_back(x - 1);

    if (!c) solve({0});
    else if (c == 1) solve({1, 2, 3, 4});
    else if (c == 2) solve({0, 1, 2, 3, 5, 6, 7});
    else solve({0, 1, 2, 3, 4, 5, 6, 7});
}