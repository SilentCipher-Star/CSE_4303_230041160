#include <iostream>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long max1 = LLONG_MIN, max2 = LLONG_MIN, max3 = LLONG_MIN;
    long long x;

    for(int i = 1; i <= N; i++) {
        cin >> x;

        if(x > max1) {
            max3 = max2;
            max2 = max1;
            max1 = x;
        }
        else if(x > max2) {
            max3 = max2;
            max2 = x;
        }
        else if(x > max3) {
            max3 = x;
        }

        if(i < 3) {
            cout << -1 << endl;
        } else {
            cout << (max1 * max2 * max3) << endl;
        }
    }
    return 0;
}
