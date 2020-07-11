#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

int N; 
char grid[20][20];
set<string> p1;
set<string> p2;
set<string>p;

int dx1[2]={0, 1};
int dy1[2]={1, 0};
void solve1(int x, int y, int ex, int ey, string s)
{
    if (x==ex && y==ey) {
        p1.insert(s);
        return;
    }
    s+=grid[x][y];
    for (int i=0; i<2; i++) {
        int nx=x+dx1[i];
        int ny=y+dy1[i];
        if (nx >= 0 && nx <= ex && ny >=0 && ny <= ey) {
            solve1(nx, ny, ex, ey, s);
        }
    }
}

int dx2[2]={0, -1};
int dy2[2]={-1, 0};
void solve2(int x, int y, int ex, int ey, string s)
{
    if (x==ex && y==ey) {
        p2.insert(s);
        return;
    }
    s+=grid[x][y];
    for (int i=0; i<2; i++) {
        int nx=x+dx2[i];
        int ny=y+dy2[i];
        if (nx < N && nx >= ex && ny < N && ny >= ey) {
            solve2(nx, ny, ex, ey, s);
        }
    }
}

string reverse(string s) {
    string ns;
    for (int i=0; i<s.length(); i++) {
        ns+=s[s.length()-i-1];
    }
    return ns;
}

int main()
{
    cin>>N; 
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin>>grid[i][j];
        }
    }
    
    set <string>::iterator itr;
    set <string>::iterator itr2;
    for (int i=0; i<N; i++) {
        solve1(0, 0, i, N-i-1, "");
        solve2(N-1, N-1, i, N-i-1, "");

        for (itr=p1.begin(); itr != p1.end(); itr++) {
            string a=*itr; 
            if (p2.count(a)==1) {
                string pal=a+grid[i][N-i-1]+reverse(a);
                p.insert(pal);
            }
        }
        p1.clear();
        p2.clear();
    }
    cout<<p.size()<<'\n';
}