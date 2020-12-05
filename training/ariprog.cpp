/*
ID: drayale1
LANG: C++
TASK: ariprog
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 250 * 250 * 2 + 10;
int n, m;
bool st[N];
struct Seq {
    int a, b;
    bool operator< (const Seq& t) const {
        if (b != t.b) return b < t.b;
        return a < t.a;
    }
} seq[10000];

int main() {
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= m; i++)
        for (int j = i; j <= m; j++)
            st[i * i + j * j] = true;
    
    int cnt = 0, S = m * m * 2;
    for (int i = 0; i <= S; i++)
        if (st[i]) {
            for (int j = i + 1; j <= S; j++) {
                if (st[j]) {
                    int d = j - i;
                    int last = i + d * (n - 1);
                    if (last > S) break;
                    bool flag = true;
                    for (int k = j + d; k <= last; k += d) {
                        if (!st[k]) {
                            flag = false;
                            break;
                        }
                    }
                    Seq temp; 
                    temp.a = i, temp.b = d;
                    if (flag) seq[cnt++] = temp;
                }
            }
        }
    
    if (!cnt) puts("NONE");
    else {
        sort(seq, seq + cnt);
        for (int i = 0; i < cnt; i++) 
            printf("%d %d\n", seq[i].a, seq[i].b);
    }
    return 0;
}