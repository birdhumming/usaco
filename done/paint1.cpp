#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int n, q;
string s;
bool seen[30];
int s1[N], s2[N];
//s1[i] = number of strokes it takes to paint the fence from 1-i
//s2[i] = number of strokes it takes to paint the fence from i - n

//ABBAABCB
//AAAAAAAA 1
//ABBAABBB 2
//ABBAABCB 1
//3 6
//1 2    7 8

//1 4
//1 1    5 8


int main() {
    cin >> n >> q >> s;
    string t = "@" + s;

    //string t = "ABCBA";
    //cout << calc(t) << endl;

    memset(seen, true, sizeof seen);
    for (int i = 1; i <= n; i++) {
        char c = t[i];
        for (char j = c + 1; j <= 'Z'; j++) seen[j - 'A'] = true;

        if (seen[c - 'A']) s1[i]++;
        seen[c - 'A'] = false;

        s1[i] += s1[i - 1];
    }

    memset(seen, true, sizeof seen);
    t += "@";
    for (int i = n; i >= 1; i--) {
        char c = t[i];
        //cout << "c = " << c << endl;
        for (char j = c + 1; j <= 'Z'; j++) seen[j - 'A'] = true;

        if (seen[c - 'A']) s2[i]++;
        seen[c - 'A'] = false;
        
        s2[i] += s2[i + 1];
    }

    //for (int i = 1; i <= n; i++) cout << s1[i] << " ";
    //cout << endl;
    //for (int i = 1; i <= n; i++) cout << s2[i] << " ";
    //cout << endl;

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        //cout << "a = " << a << ", b = " << b << endl;
        //cout << "s1[a] = " << s1[a] <<", s1[a - 1] = " << s1[a - 1] << ", s1[a + 1] = " << s1[a + 1] << endl;
        //cout << "s2[b] = " << s2[b] <<", s2[b - 1] = " << s2[b- 1] << ", s2[b + 1] = " << s2[b + 1] << endl;
        cout << s1[a - 1] + s2[b + 1] << endl;
    }
}