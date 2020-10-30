#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int n, k;
int bales[50001];

bool cover(int r) {
    int c = 1;
    int b = bales[0] + 2 * r;
    for (int i = 0; i < n; i++) 
        if (bales[i] > b) {
            c++;
            b = bales[i] + 2 * r;
        }
    if (c > k) return false;
    return true;
}

int bin_search(int low, int mid, int hi)
{
    //cout<<mid<<'\n';
    if (cover(mid) && !cover(mid - 1)) {
        //cout<<mid<<" "<<mid-1<<'\n';
        return mid;
    }
    if (cover(mid)) return bin_search(low, (low + mid)/2, mid);
    else return bin_search(mid + 1, (mid + 1 + hi) / 2, hi);
}

int main()
{
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) scanf("%d", &bales[i]);
    sort(bales, bales + n);
    int r = bin_search(1, (bales[0] + bales[n - 1]) / 2, bales[n - 1] - bales[0]);
    //if (cover(1)) cout<<"39\n";
    printf("%d\n", r);

    return 0;
}
