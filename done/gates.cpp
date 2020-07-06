#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

vector <ii> vertices;
vector <pair<ii, ii> > edges;

bool vunvisted (ii a)
{
    for (int i=0; i<vertices.size(); i++) {
        if (vertices[i]==a) return false;
    }
    return true;
}

bool eunvisited(pair <ii, ii> a) 
{
    for (int i=0; i<edges.size(); i++) {
        if (edges[i]==a) return false;
    }
    return true;
}

int main()
{
    int N; cin>>N;
    string s;
    cin>>s;

    int x=0, y=0;
    int xpre, ypre;

    ii temp; temp.first=x; temp.second=y;
    vertices.push_back(temp);

    for (int i=0; i<N; i++) {
        xpre=x;
        ypre=y;
        char c=s[i];
        if (c=='N') {
            x=xpre;
            y=ypre+1;
        }
        if (c=='S') {
            x=xpre;
            y=ypre-1;
        }
        if (c=='E') {
            x=xpre+1;
            y=ypre;
        }
        if (c=='W') {
            x=xpre-1;
            y=ypre;
        }
        temp.first=x; temp.second=y; 
        if (vunvisted(temp)) {
            vertices.push_back(temp);
        }

        if (c=='N' || c=='E') {
            ii temp2;
            temp.first=xpre; temp.second=ypre;
            temp2.first=x; temp2.second=y;
            pair <ii, ii> temp3;
            temp3.first=temp; temp3.second=temp2;
            if (eunvisited(temp3)) {
                edges.push_back(temp3);
            }
        }
        else {
            ii temp2;
            temp.first=x; temp.second=y;
            temp2.first=xpre; temp2.second=ypre;
            pair <ii, ii> temp3;
            temp3.first=temp; temp3.second=temp2;
            if (eunvisited(temp3)) {
                edges.push_back(temp3);
            }
        }
    }
   
    cout<<edges.size()-vertices.size()+1<<'\n';
}