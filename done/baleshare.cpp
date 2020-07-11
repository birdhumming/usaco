#include <iostream>
using namespace std;

int N;
int sizes[21];
int ans=10000000;

int solve(int b1, int b2, int b3, int i)
{
    if (i==N) return max(b1, max(b2, b3));

    if (b1 + sizes[i] < ans) ans=min(ans, solve(b1 + sizes[i], b2, b3, i+1));

    if (b2+sizes[i] > b1 && b2+sizes[i] < ans) ans=min(ans, solve(b2+sizes[i], b1, b3, i+1));
    else if (b2+sizes[i] < ans) ans=min(ans, solve(b1, b2+sizes[i], b3, i+1));

    if (b3+sizes[i] > b1 && b3+sizes[i] < ans) ans=min(ans, solve(b3+sizes[i], b1, b2, i+1));
    else if (b3+sizes[i] < ans) ans=min(ans, solve(b1, b2, b3+sizes[i], i+1));

    return ans;
}

int main()
{
    cin>>N;
    for (int i=0; i<N; i++) cin>>sizes[i];

    cout<<solve(0, 0, 0, 0)<<'\n';
}