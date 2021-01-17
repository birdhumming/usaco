/*
ID: drayale1
LANG: C++
TASK: prefix
*/

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

typedef unsigned long long ull;
const int N = 200010, P = 131;

string str;
bool f[N];

int main() {
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    unordered_set<ull> hash;
    while (cin >> str, str != ".") {
        ull h = 0;
        for (int i = str.size() - 1; i >= 0; i--)
            h = h * P + str[i];
        hash.insert(h);
    }

    str.clear();
    string line;
    while (cin >> line) str += line;

    int res = 0;
    f[0] = true;
    for (int i = 1; i <= str.size(); i++) {
        ull h = 0;
        for (int j = i; j > i - 10 && j > 0; j--) {
            h = h * P + str[j - 1];
            if (hash.count(h) && f[j - 1]) {
                f[i] = true;
                break;
            }
        }
        if (f[i]) res = i;
    }
    cout << res << endl;
}   