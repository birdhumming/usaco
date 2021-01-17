#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

const int N = 1010;
int n;
struct cow {
    int x, y, len = 2 * 1e9;
} cows[N];
int east[N], north[N];
int east_size, north_size;
int stopped[N];
bool is_stopped[N];

bool cmp(int a, int b) {
    return cows[a].x < cows[b].x;
}

bool cmp1(int a, int b) {
    return cows[a].y < cows[b].y;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        char dir; int x, y;
        cin >> dir >> x >> y;
        if (dir == 'E') {
            east[east_size++] = i;
        }
        else {
            north[north_size++] = i;
        }

        cows[i].x = x, cows[i].y = y;
    }

    sort(east, east + east_size, cmp1);
    sort(north, north + north_size, cmp);

    for (int i = 0; i < east_size; i++) {
        for (int j = 0; j < north_size; j++) {
            int a = east[i];
            int b = north[j];

            if (is_stopped[a] || is_stopped[b] || cows[a].x > cows[b].x || cows[a].y < cows[b].y)
                continue;
            
            if (cows[b].x - cows[a].x > cows[a].y - cows[b].y) {
                is_stopped[a] = true;
                stopped[b] += 1 + stopped[a];
            }
            else if (cows[a].y - cows[b].y > cows[b].x - cows[a].x) {
                is_stopped[b] = true;
                stopped[a] += 1 + stopped[b];
            }
        }
    }

    for (int i = 0; i < n; i++) cout << stopped[i] << endl;
}