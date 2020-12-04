/*
ID: drayale1
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

const int N = 10;
int n;
string names[N];
unordered_map<string, int> person;

int main() {
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> names[i];

    for (int i = 0; i < n; i++) {
        string name; int money, cnt;
        cin >> name >> money >> cnt;
        if (cnt) {
            person[name] -= money / cnt * cnt;
            for (int j = 0; j < cnt; j++) {
                string p; cin >> p;
                person[p] += money / cnt;
            }
        }
    }

    for (int i = 0; i < n; i++) 
        cout << names[i] << ' ' << person[names[i]] << endl;
    

    return 0;
}