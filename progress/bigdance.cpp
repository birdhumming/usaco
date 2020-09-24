#include <iostream>
using namespace std;

int N, ans=0;

int solve(int first, int last)
{
    if (last-first==1) {
        ans+=first*last;
        return 0;
    }
    if (first==last) return 0;
    solve(first, (first+last)/2);
    solve(((first+last)/2)+1, last);
}

int main()
{
    cin>>N;
    solve(1, N);
    cout<<ans<<'\n';
}