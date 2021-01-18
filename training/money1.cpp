/*
ID: drayale1
LANG: C++
TASK: money
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int N = 10010;
int v, n;
ll f[N];
bool visited[N];
vector<int> coins;

int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    cin >> v >> n;
    coins.push_back(0);
    for (int i = 0; i < v; i++) {
        int c; cin >> c;
        coins.push_back(c);
    }
    memset(f, 0, sizeof f);
    f[0] = 1;


    for (int i = 1; i <= v; i++)
        for (int j = coins[i]; j <= n; j++) {
            f[j] += f[j - coins[i]];
        }
    
    //for (int i = 0; i <= n; i++) cout << f[i] << endl;
    cout << f[n] << endl;


}