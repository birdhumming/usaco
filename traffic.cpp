#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<pair<string, pair<int, int> > > road;

int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    int n; cin >> n;
    road.resize(n);
    for (int i = 0; i < N; i++) {
        cin >> road[i].first >> road[i].second.first >> road[i].second.second;
    }

    string status;
    int x, y;
    int cl = 0, ch = 0; ; //change low, chang high
    int rl = 0, rh = 1001; //range low, range high
    int i = 0;
    status = road[i].first, x = road[i].second.first, y =r oad[i].second.second;

    while (i < n) {
        if (status == "none") {
            while (status == "none") {
                if (x > rl) rl = x;
                if (y < rh) rh = y;
                i++;
                status = road[i].first, x = road[i].second.first, y = road[i].second.second; 
            }
            break;
        }
        else {
            while (status != "none") {
                if (status == "on") {
                    cl += x;
                    ch += y;
                }
                if (status == "off") {
                    cl -= y;
                    ch -= x;
                }
                i++;
                status = road[i].first, x = road[i].second.first, y = road[i].second.second; 
            }
        }
    }
    
    if (rl - ch < 0 && rh - cl < 0) cout << 0 << " " << 0 << '\n';
    else if (rl - ch < 0) cout << 0 << " " << rh - cl << '\n';
    else cout << rl - ch << " "<< rh - cl << '\n';

    //cout<<"range low: "<<rl<<'\n';
    //cout<<"range high: "<<rh<<'\n';
    //cout<<"change low: "<<cl<<'\n';
    //cout<<"change high: "<<ch<<'\n';
    cl = 0, ch = 0;
    rl = 0, rh = 1001;
    i = n - 1;
    status = road[i].first, x = road[i].second.first, y = road[i].second.second;
    while (i >= 0) {
        if (status == "none") {
            while (status == "none") {
                if (x > rl) rl = x;
                if (y < rh) rh = y;
                i--;
                status = road[i].first, x = road[i].second.first, y = road[i].second.second; 
            }
            break;
        }
        else {
            while (status != "none") {
                if (status == "on") {
                    cl += x;
                    ch += y;
                }
                if (status == "off") {
                    cl -= y;
                    ch -= x;
                }
                i--;
                status = road[i].first, x = road[i].second.first, y = road[i].second.second; 
            }
        }
    }
    if (rl + cl < 0 && rh + ch < 0) cout << 0 << " " << 0 << '\n';
    else if (rl + cl < 0) cout << 0 <<" " << rh + ch << '\n';
    else cout << rl + cl << " " << rh + ch<< '\n';
    //cout<<"range low: "<<rl<<'\n';
    //cout<<"range high: "<<rh<<'\n';
    //cout<<"change low: "<<cl<<'\n';
    //out<<"change high: "<<ch<<'\n';
    return 0;
}