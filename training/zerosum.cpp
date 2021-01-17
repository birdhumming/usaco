/*
ID: drayale1
LANG: C++
TASK: zerosum
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

bool check(string num) {
    num = '+' + num;
    int res = 0;
    for (int i = 0; i < num.size(); i++) {
        int j = i + 1, x = 0;
        while (j < num.size() && num[j] != '+' && num[j] != '-') {
            char c = num[j];
            if (c != ' ') x = x * 10 + c - '0';
            j++;
        }
        if (num[i] == '+') res += x;
        else res -= x;
        i = j - 1;
    }
    return res == 0;
}

void dfs(int u, string num) {
    if (u > n) {
        if (check(num)) cout << num << endl;
        return;
    }

    char ops[3] = {' ', '+', '-'};
    for (auto op : ops) 
        dfs(u + 1, num + op + to_string(u));
}

int main() {
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    cin >> n;
    dfs(2, "1");
}