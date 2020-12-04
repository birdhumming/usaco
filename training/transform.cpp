/*
ID: drayale1
LANG: C++
TASK: transform
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<string> vs;

int n;

//reflect over central vertical line
void reflect(vs& s) {
    for (int i = 0; i < n; i++)
        for (int j = 0, k = n - 1; j < k; j ++, k--)
            swap(s[i][j], s[i][k]);
}

//rotate 90 degrees clockwise
void rotate(vs& s) {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < i; j++)
        swap(s[i][j], s[j][i]);
    reflect(s);
}

int check(vs& a, vs& b) {
    auto c = a;
    for (int i = 1; i <= 3; i++) {
        rotate(c);
        if (c == b) return i;
    }

    c = a;
    reflect(c); 
    if (c == b) return 4;

    for (int i= 1; i <= 3; i++) {
        rotate(c);
        if (c == b) return 5;
    }

    if (a == b) return 6;
    return 7;
}

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    vs a, b; string line;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> line, a.push_back(line);
    for (int i = 0; i < n; i++) cin >> line, b.push_back(line);

    cout << check(a, b) << endl;
    return 0;
}

//only two tranformations: reflect and rotate 90 deg
//reflect can be done w/ 2 pointers and swap
//rotate 90 deg - reflect top-left to bottom-right diagonally, then reflect vertically