#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

const int N = 55;
int n;
int east_size, north_size;
ii east[N], north[N];

struct Cow {
    char dir;
    int x, y;
    int len;
} Cows[N];

bool cmp(ii a, ii b) {
    return a.second < b.second;
}

int solve_east(int x, int y);

int solve_north(int x, int y, vector<ii>& cows) {
    //cout << "x = "<<x<<", y = "<<y<<endl;

    if (cows.empty()) return -1;
    sort(cows.begin(), cows.end(), cmp);

    for (ii cow : cows) {
        int x1 = cow.first, y1 = cow.second;
        //cout << "x1 = "<<x1<<", y1 = "<<y1<<endl;
        if (x - x1 < y1 - y) return y1 - y;
    }

    return -1;
}

int solve_east(int x, int y, vector<ii>& cows) {
    //cout << "x = "<<x<<", y = "<<y<<endl;
    if (cows.empty()) return -1;
    sort(cows.begin(), cows.end());

    for (ii cow : cows) {
        int x1 = cow.first, y1 = cow.second;
        //cout << "x1 = "<<x1<<", y1 = "<<y1<<endl;
        if (x1 - x > y - y1) return x1 - x;
    }

    return -1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        char dir; int x, y; 
        cin >> dir >> x >> y;
        if (dir == 'E') 
            east[east_size++] = make_pair(x, y);
        
        if (dir == 'N') 
            north[north_size++] = make_pair(x, y);

        Cows[i].dir = dir;
        Cows[i].x = x, Cows[i].y = y;
    }

    for (int i = 0; i < n; i++) {
        int x = Cows[i].x, y = Cows[i].y;
        int direction = Cows[i].dir;
        int res;
        if (direction == 'N') {
            vector<ii> cows;
            for (int j = 0; j < east_size; j++) {
                if (y <= east[j].second && x >= east[j].first) 
                    cows.push_back(east[j]);
            }
            res = solve_north(x, y, cows);
        }

        else if (direction == 'E') {
            vector<ii> cows;
            for (int j = 0; j < north_size; j++) {
                if (y >= north[j].second && x <= north[j].first) 
                    cows.push_back(north[j]);
            }
            res = solve_east(x, y, cows);
        }
        Cows[i].len = res;
    
        //if (res == -1) cout << "Infinity\n";
        //else cout << res << endl;

    }

    for (int i = 0; i < n; i++) {
        int x = Cows[i].x, y = Cows[i].y;
        int direction = Cows[i].dir;
        int length = Cows[i].len;

        int res;
        if (direction == 'N') {
            vector<ii> cows;
            for (int j = 0; j < n; j++) {
                if (Cows[j].dir == 'N') continue;
                int x1 = Cows[j].x, y1 = Cows[j].y;
                if (y <= y1 && x >= x1 && (x - x1 <= Cows[j].len || Cows[j].len == -1)) 
                    cows.push_back(make_pair(x1, y1));
            }
            res = solve_north(x, y, cows);
        }

        else if (direction == 'E') {
            vector<ii> cows;
            for (int j = 0; j < n; j++) {
                if (Cows[j].dir == 'E') continue;
                int x1 = Cows[j].x, y1 = Cows[j].y;
                if (y >= y1 && x <= x1 && (y - y1 <= Cows[j].len || Cows[j].len == -1)) 
                    cows.push_back(make_pair(x1, y1));
            }
            res = solve_east(x, y, cows);
        }
        Cows[i].len = res;
    
        if (res == -1) cout << "Infinity\n";
        else cout << res << endl;

    }

    /*for (int i = 0; i < north_size; i++) {
        int x = north[i].first, y = north[i].second;

        int res = solve_north(x, y);
        if (res == -1) cout << "Infinity\n";
        else cout << res << endlif (res == -1) cout << "Infinity\n";
        else cout << res << endl;
    }

    for (int i = 0; i < east_size; i++) {
        int x = east[i].first, y = east[i].second;

        int res = solve_east(x, y);
        if (res == -1) cout << "Infinity\n";
        else cout << res << endl;
    }*/
}