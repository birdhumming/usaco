#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, pair<int, int> > iii;

void print_iii(iii a) {
    cout<<a.first<<" "<<a.second.first<<" "<<a.second.second<<'\n';
}
int main() 
{
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    

}


/*int grid[1001][1001];
int dr[4]={1, 0, -1, 0};
int dc[4]={0, 1 ,0, -1};
int N;
vector<pair<int, int> > blobs;
vector<int> size_arr;
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
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (grid[i][j]==1) {
                int size=floodfill(i, j);
                size_arr.push_back(size);
            }
        }
    }
    int max_size=0;
    for (int i=0; i<size_arr.size(); i++) {
        if (size_arr[i]>max_size) max_size=size_arr[i];
    }
    for (int i=0; i<size_arr.size(); i++)
        cout<<'\n';
    for (int i=0; i<blobs.size(); i++) {
        cout<<blobs[i].first<<" "<<blobs[i].second<<'\n';
    }
}

int floodfill(int r, int c) {
    if (r<0 || r>=N || c<0 || c>=N) return 0;
    if (grid[r][c]==0) return 0;
    int perim=0;
    perim+=adjnum(r, c);
    int size=1;
    grid[r][c]=0;
    for (int d=0; d<4; d++) {
        size+=floodfill(r+dr[d], c+dc[d]);
    }
    cout<<"size: "<<size<<", perim: "<<perim<<'\n';
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

// C++ program to find perimeter of area coverede by 
// 1 in 2D matrix consisits of 0's and  1's. 
#include<bits/stdc++.h> 
using namespace std; 
#define R 3 
#define C 5 
  


  
// Returns sum of perimeter of shapes formed with 1s 
int findperimeter(int mat[R][C]) 
{ 
    int perimeter = 0; 
  
    // Traversing the matrix and finding ones to 
    // calculate their contribution. 
    for (int i = 0; i < R; i++) 
        for (int j = 0; j < C; j++) 
            if (mat[i][j]) 
                perimeter += (4 - numofneighbour(mat, i ,j)); 
  
    return perimeter; 
} 
  
// Driven Program 
int main() 
{ 
    int mat[R][C] = 
    { 
        0, 1, 0, 0, 0, 
        1, 1, 1, 0, 0, 
        1, 0, 0, 0, 0, 
    }; 
  
    cout << findperimeter(mat) << endl; 
  
    return 0; 
} */
