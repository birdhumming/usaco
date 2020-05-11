#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

char property[10][10];
int bx, by, rx, ry, lx, ly, ans;

bool y_inbetween(int r)
{
    if ((ly<ry && ry<by) || (by<ry && ry<ly)) return true;
    return false;
}
bool x_inbetween(int r)
{
    if ((lx<rx && rx<bx) || (bx<rx && rx<lx)) return true;
    return false;
}

int main()
{
    ifstream fin ("buckets.in");
    ofstream fout ("buckets.out");
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            fin>>property[i][j];
            if (property[i][j] == 'B') { bx=i, by=j; }
            if (property[i][j] == 'R') { rx=i, ry=j; }
            if (property[i][j] == 'L') { lx=i, ly=j; }
        }
    }
    if (bx==lx)
    {
        ans=abs(by-ly)-1;
        if (rx==bx && y_inbetween(ry)) { ans+=2; }
        fout<<ans;
        return 0;
    }
    if (by==ly)
    {
        ans=abs(bx-lx)-1;
        if (ry==by && x_inbetween(rx)) { ans+=2; }
        fout<<ans;
        return 0;
    }
    ans= abs(bx-lx) + abs(by-ly) -1;
    fout<<ans;
}