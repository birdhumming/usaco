#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

int N, a, b;
unordered_map<int, vector<int> > x; //y[i] is x coordinates of points with y coord i
unordered_map<int, vector<int> > y; //vv
unordered_map<ii, char> m; //mirror location, orientation
vector<ii> ml; //mirror locations in order

int main()
{
    cin>>N>>a>>b;
    x[a]=b; y[b]=a;
    for (int i=0; i<N; i++) {
        int w, z; char c;
        cin>>w>>z>>c;
        ii temp; temp.first=w, temp.second=z;
        m[temp]=c;
        ml.push_back(temp);
    }
    
}