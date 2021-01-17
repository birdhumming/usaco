#include <iostream>
using namespace std;

int n;
int f[3], m[3];

bool works(int a, int b, int c) {
    if ((abs(f[0] - a) <= 2 || n - (abs(f[0] - a)) <= 2) && (abs(f[1] - b) <= 2 || n - (abs(f[1] - b))) && (abs(f[2] - c) <= 2 || n - (abs(f[2] - c)))) {
        //cout << "a = " << a << ", b = " << b << ", c = " << c <<endl;
        return true;
    }

    if ((abs(m[0] - a) <= 2 || n - (abs(m[0] - a)) <= 2) && (abs(m[1] - b) <= 2 || n - (abs(m[1] - b))) && (abs(m[2] - c) <= 2 || n - (abs(m[2] - c)))) {
        //cout << "a = " << a << ", b = " << b << ", c = " << c <<endl;
        return true;
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < 3; i++) cin >> f[i];
    for (int i = 0; i < 3; i++) cin >> m[i];

    int ans = 0;
    for (int a = 1; a <= n; a++)
        for (int b = 1; b <= n; b++)
            for (int c = 1; c <= n; c++) 
                if (works(a, b, c)) 
                    ans++;

    cout << ans << endl;
}