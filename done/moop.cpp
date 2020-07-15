#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;

int N; 
ii coords[100002];
int minYfromLeft[100002], maxYfromRight[100002];

int main()
{
    cin>>N;
    for (int i=0; i<N; i++) cin>>coords[i].first>>coords[i].second;
    sort(coords, coords+N);
    minYfromLeft[0]=coords[0].second;
    maxYfromRight[N-1]=coords[N-1].second;
    for (int i=1; i<N; i++) {
        minYfromLeft[i]=min(minYfromLeft[i-1], coords[i].second);
    }
    for (int i=N-2; i>=0; i--) {
        maxYfromRight[i]=max(maxYfromRight[i+1], coords[i].second);
    }
    int ans=1;
    for (int i=0; i<N-1; i++) {
        if (minYfromLeft[i] > maxYfromRight[i+1]) ans++;
    }
    cout<<ans<<'\n';
}