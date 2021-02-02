#include <bits/stdc++.h> 
using namespace std; 

const int N = 110;
int n, a[N];
int s[N][N];

 bool check(int x) {
    return a[x] < 8;
}

int main() {
    cin >> n;

    int x1, y1, x2, y2;
    //rectangle with upper left (x1, y1) and lower right (x2, y2)
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1++, y1++, x2++, y2++; //only do if 0 is possible
        
        s[x1 - 1][y1 - 1]++;
        s[x2][y2]++;
        
        s[x1 - 1][y2]--;
        s[x2][y1 - 1]--;
    }

    //prefix sum
    for (int i = 1; i < N; i++) { //N is max x
        for (int j = 1; j < N; j++) { //M is max y
            s[i][j] += (s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]);
        }
    }

    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) 
            cout << s[i][j] << " ";
        cout << endl;
    }
}