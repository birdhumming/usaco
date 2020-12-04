/*
ID: drayale1
LANG: C++
TASK: friday
*/

#include <iostream>
using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int weekday[7];

int main() {
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    int n; cin >> n;

    int year = 1900, days = 0;
    while (n--) {
        for (int i = 1; i <= 12; i++) {
            weekday[(days + 12) % 7]++;
            days += month[i];
            if (i == 2)
                if (year % 4 == 0 && year % 100 || year % 400 == 0)
                    days++;
        }
        year++;
    }

    for (int i = 5, j = 0; j < 7; i++, j++) {
        cout << weekday[i % 7];
        if (j != 6) cout << ' ';
    }
    cout << endl;
    
    return 0;
}