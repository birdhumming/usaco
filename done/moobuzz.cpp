#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> stor; // first 8 numbers
 
bool ok(int x) { return x % 3 && x % 5; } 

int solve(int N) {
	int num = (N - 1) / 8;
	return stor[N - 8 * num - 1] + 15 * num;
}
 
int main() {

    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);

    for (int i = 1; i < 16; i++) {
        if (ok(i)) stor.push_back(i);
    }

	int N; cin >> N;
	cout << solve(N) << "\n";
}