#include <iostream>
using namespace std;

const int N = 2 * 1e5 + 10;
int n, m;
int p[N];

int find (int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (a >= n) swap(a, b);
    p[b] = a;
}

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < N; i++) p[i] = i;

    for (int i = 0; i < m; i++) {
        int a, b; char c;
        cin >> c >> a >> b;
        //cout << a << " " << b << endl;
        a--, b--;
        if (a > b) swap(a, b);

        if (c == 'S') {
            merge(a, b);
            merge(a + n, b + n);
        }
        else {
            merge(a, b + n);
            merge(b, a + n);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (find(i) == find(i + n)) {
            printf("0");
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
        merge(i, i + n);
    
    printf("1");
    for (int i = 0; i < n; i++) {
        if (i == find(i)) printf("0");
    }
    cout<<endl;
    return 0;
}