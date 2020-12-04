/*
ID: drayale1
LANG: C++
TASK: namenum
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int get(char c) {
    if (c <= 'O') return (c - 'A') / 3 + 2;
    if (c <= 'S') return 7;
    if (c <= 'V') return 8;
    return 9;
}

int main() {
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
    string num, str;
    cin >> num;

    freopen("dict.txt", "r", stdin);

    int cnt = 0;
    while (cin >> str) {
        string cur;
        for (auto c : str) cur += get(c) + '0';
        if (cur == num) {
            cout << str << endl;
            cnt++;
        }
    }

    if (!cnt) puts("NONE");

    return 0;
}