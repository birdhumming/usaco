#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef pair <int, int> ii;

int N, M;
int arr[100002];
vector<ii> AL[100002];
bool visited[100002];
set <int> unpaired;

void solve(int cow, int w)
{
    visited[cow]=true;
    if (unpaired.count(cow) > 0) {
        unpaired.erase(cow);
    }
    else unpaired.insert(cow);
    if (unpaired.count(arr[cow]) > 0) {
        unpaired.erase(arr[cow]);
    }
    else unpaired.insert(arr[cow]);
    for (int i=0; i<AL[cow].size(); i++) {
        int next=AL[cow][i].first; int width=AL[cow][i].second;
        if (!visited[next] && width >= w) {
            solve(next, w);
        }
    }
}

void clear()
{
    for (int i=0; i<100002; i++) visited[i]=false;
}

int main()
{
    cin>>N>>M;
    for (int i=1; i<=N; i++) cin>>arr[i];
    for (int i=0; i<M; i++) {
        int a, b, w; cin>>a>>b>>w;
        AL[a].push_back(make_pair(b, w));
        AL[b].push_back(make_pair(a, w));
    }

    int low=1; int upp=1000000000;
    while (low != upp) {
        int mid=(low+upp+1)/2;
        bool valid=true;
        unpaired.clear();
        clear();
        for (int i=0; i<N; i++) {
            if (!visited[i]) {
                solve(i, mid);
                if (unpaired.size() > 0) {
                    valid=false;
                }
            }
        }
        if (valid) low=mid;
        else upp=mid-1;
    }
    if (low==1000000000) {
        cout<<-1<<'\n';
        return 0;
    }
    cout<<low<<'\n';
}