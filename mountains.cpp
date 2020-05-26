#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<pair<int, int> > peaks;

bool is_in(int x1, int y1, int x2, int y2) { //is the peak (x1, y1) within the mountain (x2, y2)
    if (x1==-1 || x2==-1) return false;
    if (x2-y2 >= x1-y1 && x2+y2 >= x1+y1) return true;
    return false;
}

int main() {
    ifstream fin ("mountains.in");
    ofstream fout ("mountains.out");
    int N, x, y; fin>>N;
    int count=0, ans=0;
    for (int i=0; i<N; i++) {
        //cout<<"i = "<<i<<'\n';
        fin>>x>>y;
        for (int j=0; j<peaks.size(); j++) {
            if (is_in(x, y, peaks[j].first, peaks[j].second)) { //(x, y) is inside/on peaks[j].first;
                count=-1;
                break;
            }
            else if (is_in(peaks[j].first, peaks[j].second, x, y)) { //current peaks is in (x, y)
                peaks[j].first=-1;
                count++;
            }
            //cout<<"j = "<<j<<", count = "<<count<<'\n';
        }
        if (count!=-1) {
            pair<int, int> temp;
            temp.first=x, temp.second=y;
            peaks.push_back(temp);
        }
        if (count==0) ans++;
        if (count>0) {

            ans-=count;
            ans++;
        }
        count=0;
    }
    fout<<ans;
}
