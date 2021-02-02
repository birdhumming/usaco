#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

int n;
vector<int> e, b;

bool cmp(int a, int b) {
    if (e[a] )
}

int main() {
    //freopen("highcard.in", "r", stdin);
    //freopen("highcard.out", "w", stdout);

    scanf("%d", &n);
    e.resize(n), b.resize(n);
    vector<int> used(2*n + 10, 0);
    //0 means unvisited, 1 means elsie, 2 means bessie

    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        used[x] = 1;
        e[i] = x;
        
    }

    //sort(e.begin(), e.end());
    int ans = 0;
    int bgreater = 0;
    for (int i = 2 * n; i > 0; i--) {
        //cout<<"i = "<<i<<", used[i] = "<<used[i]<<endl;
        if (used[i] == 0) bgreater++;
        //cout<<"bgreater = "<<bgreater<<endl;

        if (used[i] == 1) {
            if (bgreater > 0) { ans++; bgreater--; }
        }
    }

    cout<<ans<<endl;
    
    return 0;
}