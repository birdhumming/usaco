#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ii pair<int, int>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vii vector<ii>
#define pb push_back
#define rz resize
#define mp make_pair
#define ff first
#define ss second

#define FOR(n) for (int i = 0; i < n; i++)
#define FOR1(n) for (int i = 1; i <= n; i++)
#define RFOR(n) for (int i = n - 1; i >= 0; i--)
#define DFOR(n, m) FOR(n) for (int j = 0; j < m; j++)

int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};
int ddx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int ddy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

bool in_bounds(int x, int y, int n, int m) {
    if (x >= 0 && x < n && y >= 0 && y < m) return true;
    return false;
}

int a1, a2;
int b1, b2;
int c1, c2;

void insert_ab() {
    int b = b2;
    b2 = min(b1, b2 + a2);
    a2 = max(0, a2 - (b1 - b));
}

void insert_bc() {
    int c = c2;
    c2 = min(c1, c2 + b2);
    b2 = max(0, b2 - (c1 - c));
}

void insert_ca() {
    int a = a2;
    a2 = min(a1, a2 + c2);
    c2 = max(0, c2 - (a1 - a));
}

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    cin >> c1 >> c2;

    for (int i = 1; i <= 100; i++) {
        //cout << a2 << " "<< b2 << " " << c2 << endl;
        if (i % 3 == 1) 
            insert_ab();
        if (i % 3 == 2)
            insert_bc();
        if (i % 3 == 0) 
            insert_ca();
        //cout << a2 << " "<< b2 << " " << c2 << endl;
    }

    cout << a2 << endl << b2 << endl << c2 << endl;

    return 0;
}