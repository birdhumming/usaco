/*
ID: drayale1
LANG: C++
TASK: pprime
*/

//exceeds memory limit
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e7 + 10;

int primes[N], cnt;
bool st[N];

void init(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

bool check(int x)
{
    string s = to_string(x);
    for (int i = 0, j = s.size() - 1; i < j; i ++, j -- )
        if (s[i] != s[j])
            return false;
    return true;
}

int main()
{
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    init(N - 1);
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = 0; i < cnt; i ++ )
    {
        int p = primes[i];
        if (p >= a && p <= b && check(p))
            printf("%d\n", p);
    }

    return 0;
}