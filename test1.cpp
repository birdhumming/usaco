#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int n;
unordered_map<string, int> year;
unordered_map<string, int> track;
unordered_map<string, string> cow_year;

void init() {
    year["Ox"] = 0;
    year["Tiger"] = 1;
    year["Rabbit"] = 2;
    year["Dragon"] = 3;
    year["Snake"] = 4;
    year["Horse"] = 5;
    year["Goat"] = 6;
    year["Monkey"] = 7;
    year["Rooster"] = 8;
    year["Dog"] = 9;
    year["Pig"] = 10;
    year["Rat"] = 11;
    cow_year["Bessie"] = "Ox";
}

int main() {
    init();
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        int j = 1;
        string cow1, cow2, yr1, yr2;
        bool prev = false;
        while (j <= 8) {
            cin >> s;
            if (j == 1) cow1 = s;
            if (j == 8) cow2 = s;
            if (j == 4) {
                if (s == "previous") prev = true;
            }
            if (j == 5) yr1 = s;
            j++;
        }
        cow_year[cow1] = yr1;
        //cout << "i = " << i << endl;
        yr2 = cow_year[cow2];

        if (prev) {
            int num = 0;
            if (year[yr2] < year[yr1])
                num = 12 - year[yr1] + year[yr2];
            else {
                num = year[yr2] - year[yr1];
            }
            //cout << "Nu =" << num << endl;
            num *= -1;
            track[cow1] = track[cow2] + num;
        }
        else {
            int num = 0;
            if (year[yr1] < year[yr2])
                num = 12 - year[yr2] + year[yr1];
            else {
                num = year[yr1] - year[yr2];
            }
            //cout << "Num = " << num << endl;
            track[cow1] = track[cow2] + num;
        }
    }

    for (auto t : track) {
        //cout << t.first << " " << t.second << endl;
    }
    cout << abs(track["Elsie"]) << endl;
}
