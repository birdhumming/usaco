#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int grid[1001][1001];
int dr[4]={1, 0, -1, 0};
int dc[4]={0, 1 ,0, -1};
int N;
vector<pair<int, int> > size_perim;
vector<int> size_arr;
int floodfill(int r, int c);

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
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (grid[i][j]==1) {
                int size=floodfill(i, j);
                size_arr.push_back(size);
            }
        }
    }
    for (int i=0; i<size_arr.size(); i++) cout<<size_arr[i]<<" ";
    cout<<'\n';
}

int floodfill(int r, int c) {
    if (r<0 || r>=N || c<0 || c>=N) return 0;
    if (grid[r][c]==0) return 0;
    int size=1;
    grid[r][c]=0;
    for (int d=0; d<4; d++) {
        size+=floodfill(r+dr[d], c+dc[d]);
    }
    return size;
}

