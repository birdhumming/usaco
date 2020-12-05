/*
ID: drayale1
LANG: C++
TASK: milk3
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 21;
int A, B, C;
bool st[N][N][N];

struct Node {
    int a, b, c;
} q[N * N * N];

int hh, tt;

void insert(int x, int y, int z) {
    if (!st[x][y][z]) {
        Node temp;
        temp.a = x, temp.b = y, temp.c = z;
        q[++tt] = temp;
        st[x][y][z] = true;
    }
}

void bfs() {
    q[0].a = 0, q[0].b = 0, q[0].c = C;
    st[0][0][C] = true;

    while (hh <= tt) {
        auto t = q[hh++];
        int a = t.a, b = t.b, c = t.c;

        insert(a - min(a, B - b), min(a + b, B), c);
        insert(a - min(a, C - c), b, min(a + c, C));
        insert(min(a + b, A), b - min(b, A - a), c);
        insert(a, b - min(b, C - c), min(b + c, C));
        insert(min(a + c, A), b, c - min(A - a, c));
        insert(a, min(b + c, B), c - min(B - b, c));
    }
}


int main() {
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    cin >> A >> B >> C;

    bfs();

    bool flag = true;
    for (int c = 0; c <= C; c++) {
        for (int b = 0; b <= B; b++) {
            if (st[0][b][c]) {
                if (flag) {
                    cout << c;
                    flag = false;
                }
                else {
                    cout << " " << c;
                }
                break;
            }
        }
    }

    cout << endl;

    return 0;
}