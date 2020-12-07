#include <iostream>
using namespace std;

const int N = 55;
int f[N];
bool st[100];

bool mod[100];

int check(int x) {
    int res = 1;
    for (int i = 1; i < x; i++) {
        if ((x + i) % 7) res++;
    }
    return res;
}

int check2(int x) {
    for (int start = 0; start < 7; start++) {
        
    }
}

int main() {
    for (int i = 1; i <= 50; i++) {
        f[i] = max(f[i - 1], check(i));
    }

    for (int i = 0; i <= 50; i++) cout << f[i] << endl;

    return 0;
}