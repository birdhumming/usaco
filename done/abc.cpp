#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll nums[7];

int main() {
    ll sum = 0;
    for (int i = 0; i < 7; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    sort(nums, nums + 7);

    ll a = nums[0], b = nums[1];
    sum /= 4;
    ll c = sum - (a + b);

    cout << a << " " << b << " " << c << endl;

    return 0;
}