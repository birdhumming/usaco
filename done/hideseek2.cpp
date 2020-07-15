#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair <int, int> ii;

int N, M;
vector <int> AL[1002];
bool visited[1002];

int main()
{
    cin>>N>>M;
    for (int i=0; i<M; i++) {
        int a, b; cin>>a>>b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }

    int max_dist=0; int num_dist=0; int smallest_ind=1000000;
    queue <ii> q;
    q.push(make_pair(1, 0));
    visited[1]=true;
    while (!q.empty()) {
        int b=q.front().first;
        int dist=q.front().second;
        //cout<<b<<' '<<dist<<'\n';
        q.pop();
        if (dist > max_dist) {
            max_dist=dist;
            num_dist=0;
            smallest_ind=b;
        }
        num_dist++;
        smallest_ind=min(smallest_ind, b);

        for (int i=0; i<AL[b].size(); i++) {
            if (!visited[AL[b][i]]) {
                visited[AL[b][i]]=true;
                q.push(make_pair(AL[b][i], dist+1));
            }
        }
    }
    cout<<smallest_ind<<' '<<max_dist<<' '<<num_dist<<'\n';
}