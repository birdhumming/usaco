#include <iostream>
#include <algorithm>
using namespace std;
typedef pair <int, int> ii;

int N;
ii cows[50001];

bool comp1(ii a, ii b) { return a.first < b.first; }
bool comp2(ii a, ii b) { return a.second < b.second; }

bool valid(int sx, int bx, int sy, int by)
{
    if (sx > bx || sy > by) return false;
    int outside = 0;
    for (int i = 0; i < N; i++) {
        int x = cows[i].first; int y = cows[i].second;
        if (x < sx || x > bx || y < sy || y > by) outside++;
        if (outside > 3) return false;
    }
    return true;
}

int main()
{
    freopen("reduce.in", "r", stdin);
    freopen("reduce.out", "w", stdout);
    cin>>N;
    for (int i = 0; i < N; i++) cin>>cows[i].first>>cows[i].second;
    int sx[4], bx[4], sy[4], by[4]; //small x, big x, small y, big y

    sort(cows, cows+N, comp1);
    for (int i = 0; i < 4; i++) {
        sx[i] = cows[i].first;
        bx[i] = cows[N - i - 1].first;
    }
    sort(cows, cows+N, comp2);
    for (int i = 0; i < 4; i++) {
        sy[i] = cows[i].second;
        by[i] = cows[N - i - 1].second;
    }

    long ans = 10000000000000000;
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 4; c++) {
                for (int d = 0; d < 4; d++) {
                    if (valid(sx[a], bx[b], sy[c], by[d])) {
                        int area = (bx[b] - sx[a]) * (by[d] -s y[c]);
                        if (area < ans) ans = area;
                    }
                }
            }
        }
    }
    cout<<ans<<'\n';
}
