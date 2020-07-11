#include <iostream>
#include <string>
#include <set>
#include <iterator>
using namespace std;

string grid[5][5];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
set <string> ans;

void solve(int x, int y, string s) 
{
    if (s.length()==6) {
        ans.insert(s);
        return;
    }
    for (int i=0; i<4; i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (nx>=0 && nx<5 && ny>=0 && ny<5) {
            string ns=s+grid[nx][ny];
            solve(nx, ny, ns);
        }
    }
}

int main()
{
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin>>grid[i][j];
        }
    }

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            solve(i, j, "");
        }
    }
    
    cout<<ans.size()<<'\n';
}