#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int grid[1001][1001];
int dr[4]={1, 0, -1, 0};
int dc[4]={0, 1 ,0, -1};
int N;
int perim=0;
vector<pair<int, int> > blobs;
int floodfill(int r, int c);
int adjnum(int r, int c);

int main() {
    ifstream fin ("perimeter.in");
    ofstream fout ("perimeter.out");
    fin>>N;
    char c;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            fin>>c;
            if (c=='#') grid[i][j]=1;
            else grid[i][j]=0;
        }
    }
    pair <int, int> temp;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (grid[i][j]==1) {
                int size=floodfill(i, j);
                temp.first=size;
                temp.second=perim;
                blobs.push_back(temp);
            }
            perim=0;
        }
    }
    int max_size=0;
    for (int i=0; i<blobs.size(); i++) {
        if (blobs[i].first>max_size) max_size=blobs[i].first;
    }
    perim=40001;
    for (int i=0; i<blobs.size(); i++) {
        if (blobs[i].first==max_size) {
            if (blobs[i].second<perim) perim=blobs[i].second;
        }
    }
    fout<<max_size<<" "<<perim<<'\n';
}

int floodfill(int r, int c) {
    if (r<0 || r>=N || c<0 || c>=N) return 0;
    if (grid[r][c]!=1) return 0;
    perim+=4-adjnum(r, c);
    int size=1;
    grid[r][c]=2;
    for (int d=0; d<4; d++) {
        size+=floodfill(r+dr[d], c+dc[d]);
    }
    return size;
}
int adjnum(int r, int c) {
    int count=0;
    if (r>0 && grid[r-1][c]) count++;
    if (c>0 && grid[r][c-1]) count++;
    if (r<N-1 && grid[r+1][c]) count++;
    if (c<N-1 && grid[r][c+1]) count++;
    return count;
}