/*
ID: drayale1
LANG: C++
TASK: crypt1
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 10;
int n; 
bool st[N];

//check digits of a are in given set
bool check_in(int a) {
    while (a) {
        if (!st[a % 10]) return false;
        a /= 10;
    }
    return true;
}

//check length of int a == k
bool check_len(int a, int k) {
    return to_string(a).size() == k;
}

bool check(int a, int b) {
    int c = a * (b % 10), d = a * (b / 10), e = a * b;
    if (!check_in(a) || !check_in(b) || !check_in(c) || !check_in(d) || !check_in(e))
        return false;
    if (!check_len(c, 3) || !check_len(d, 3) || !check_len(e, 4))
        return false;
    return true;
}

int main() {
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        st[x] = true;
    }

    int res = 0;
    for (int a = 100; a <= 999; a++) 
        for (int b = 10; b <= 99; b++) 
            if (check(a, b))
                res++;
        
    cout << res << endl;

    return 0;
}