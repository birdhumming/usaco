#include <bits/stdc++.h> 
#include <unordered_map>
#include <unordered_set>
using namespace std; 

typedef pair<int, int> ii;
typedef long long ll;

const int N = 1e5 + 10;
int n, m;
vector<int> friends[N];
int track[N];
bool flag = false;

void dfs(int x, int c) {
    //cout << "x = " << x << endl;
    //if (flag) return;
    if (track[x] != 0 && track[x] == c) return;
    if (track[x] != 0 && track[x] != c) {
        flag = true;
        return;
    }

    track[x] = c;
    for (int y : friends[x]) {
        if (c == 1) dfs(y, 2);
        else dfs(y, 1);
    }
}

int main() {
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
        sum += (a + b);

    }

    for (int i = 1; i <= n; i++) {
        if (track[i] == 0) {
            dfs(i, 1);

            if (flag) {
                cout << "IMPOSSIBLE\n";
                //for (int i = 1; i <=n ;i++) cout << track[i] << " ";
                return 0;
            }
        }
    }

    for (int i = 1; i <=n ;i++) cout << sum - track[i] << " ";
    cout << endl;

}