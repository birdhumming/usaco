#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef pair <int, int> ii;

int N;
char board[31][31];
int opp=0; //opponent's pieces
stack <ii> ans;
bool flag=false;

vector <ii> kings;
int dx[4]={1, 1, -1, -1};
int dy[4]={1, -1, -1, 1};

bool valid(int x, int y, int i) {
    if (x + 2*dx[i] < 0) return false;
    if (x + 2*dx[i] >= N) return false;
    if (y + 2*dy[i] < 0) return false;
    if (y + 2*dy[i] >= N) return false;
    return true;
}

void print_ans(int k) {
    cout<<kings[k].first+1<<" "<<kings[k].second+1<<'\n';
    vector <ii> storage;
    for (int i=0; i<ans.size(); i++){
        storage.push_back(ans.top());
        ans.pop();
    }
    for (int i=storage.size()-1; i >=0; i--) {
        cout<<storage[i].first+1<<" "<<storage[i].second+1<<'\n';
    }
}

void solve(int x, int y, int moves, int k, vector<ii> coords)
{
    ii temp; temp.first = x; temp.second = y;
    coords.push_back(temp);
    if (moves == opp) {
        for (int i=0; i<coords.size(); i++) {
            cout<<coords[i].first+1<<" "<<coords[i].second+1<<'\n';
        }
        flag=true;
    }
    if (flag) return;
    for (int i=0; i<4; i++) {
        if (valid(x, y, i)) {
            if (board[x + dx[i]][y + dy[i]] == 'o') {
                board[x + dx[i]][y + dy[i]] = '+';
                solve(x + 2*dx[i], y + 2*dy[i], moves+1, k, coords);
                board[x + dx[i]][y + dy[i]] = 'o';
            }
        }
    }
}

int main()
{
    cin>>N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin>>board[i][j];
            if (board[i][j] == 'K') {
                ii temp; temp.first=i; temp.second=j;
                kings.push_back(temp);
            }
            if (board[i][j] == 'o') opp++;
        }
    }
    
    for (int i=0; i<kings.size(); i++) {
        vector<ii> temp;
        solve(kings[i].first, kings[i].second, 0, i, temp);
        if (flag) return 0;
    }

}