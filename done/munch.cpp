#include <iostream>
#include <fstream>
using namespace std;

int R, C;
int field[101][101];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

void find(int s) {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (field[i][j]==s-1) {
                for (int t=0; t<4; t++) {
                    int a=i+dx[t];
                    int b=j+dy[t];
                    //cout<<a<<" "<<b<<'\n';
                    if (a<R && b<C && a>=0 && b>=0 && (field[a][b]==-1 || field[a][b]==-3)) {
                        //cout<<"a = "<<a<<", b = "<<b<<'\n';
                        field[a][b] = s;
                    }
                }
            }
        }
    }
}

void fill(int x, int y)
{
    int i=1;
    while (field[0][0]==-3) {
        find(i);
        //cout<<i<<'\n';
        i++;
    }
    /*find(1);
    find(2);
    find(3);
    find(4);*/
}

int main()
{
    //ifstream fin("munch.in");
    cin>>R>>C;
    int x, y;
    field[0][0]=-3;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            char c; cin>>c;
            if (c=='*') field[i][j]=-2;
            if (c=='.') field[i][j]=-1;
            if (c=='C') {
                field[i][j]=0;
                x=i; y=j;
            }
        }
    }
    fill(x, y);
    /*for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout<<field[i][j]<<" ";
        }
        cout<<'\n';
    }*/
    cout<<field[0][0]<<'\n';
}

