#include <iostream>
#include <algorithm>
using namespace std;
typedef pair <int, int> ii;

int N;
ii pos[50001];

bool comp1(ii a, ii b) { return a.first<b.first; }
bool comp2(ii a, ii b) { return a.second<b.second; }
ii xmin[4], xmax[4], ymin[4], ymax[4];
bool check(int a, int b, int c, int d)
{
    int os=0;
    for (int i=0; i<N; i++) {
        if (pos[i].first < xmin[a].first || 
        pos[i].first > xmax[b].first ||
        pos[i].second < ymin[c].second ||
        pos[i].second > ymax[d].second )
            os++;
        if (os>3) return false;
    }
    return true;
}
bool check2(int a, int b, int c, int d) {
    if (xmin[a]==xmax[b]) return false;
    if (ymin[c]==ymin[d]) return false;
    return true;
}
long area(int a, int b, int c, int d) {
    int w=xmax[b].first; int x=xmin[a].first;
    int y=ymax[d].second; int z=ymin[c].second;
    return (w-x)*(y-z);
}

int main()
{
    cin>>N;
    for (int i=0; i<N; i++) cin>>pos[i].first>>pos[i].second;
    sort(pos, pos+N, comp1);
    for (int i=0; i<4; i++) {
        xmin[i]=pos[i];
        xmax[i]=pos[N-i-1];
    }
    sort(pos, pos+N, comp2);
    for (int i=0; i<4; i++) {
        ymin[i]=pos[i];
        ymax[i]=pos[N-i-1];
    }
    long ans=1600000002; 
    for (int a=0; a<4; a++) {
        for (int b=0; b<4; b++) {
            for (int c=0; c<4; c++) {
                for (int d=0; d<4; d++) {
                    if (check(a, b, c, d) && check2(a, b, c, d)) {
                        if (area(a, b, c, d) >= 0) {
                            /*cout<<xmin[a].first<<" "<<xmin[a].second<<'\n';
                            cout<<xmax[b].first<<" "<<xmax[b].second<<'\n';
                            cout<<xmax[c].first<<" "<<xmax[c].second<<'\n';
                            cout<<xmax[d].first<<" "<<xmax[d].second<<'\n';
                            cout<<"END\n";*/
                            //cout<<perim(a, b, c, d)<<'\n';
                            ans=min(ans, area(a, b, c, d));
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<'\n';
}