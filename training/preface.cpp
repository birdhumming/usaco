/*
ID: drayale1
LANG: C++
TASK: preface
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
string letter[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
int num[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
unordered_map<char, int> cnt;

int main() {
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0, x = i; j < 13; j++) {
            while (x >= num[j]) {
                x -= num[j];
                for (auto c : letter[j])
                    cnt[c]++;
            }
        }
    }

    string order = "IVXLCDM";
    for (auto c : order)
        if (cnt[c]) 
            cout << c << " " << cnt[c] << endl;
}