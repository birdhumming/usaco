#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define ll long long

ll qexp(ll x, ll y) {
    ll ans = 1;
    int pow = 1;
    while (y) {
        cout << "y = "<<y<<endl;
        cout << "x = "<<x<<endl;
        cout << "pow = "<<pow<<endl;
        if (y & 1) ans = ans * x;
        x *= x;
        pow++;
        y >>= 1;
    }
    return ans;
}

int main() {
    
    ll res = qexp(14, 5);
    cout << res << endl;
}
