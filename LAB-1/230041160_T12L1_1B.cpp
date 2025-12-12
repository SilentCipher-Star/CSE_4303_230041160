#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> v;
    int n;

    while (true) {
        cin >> n;
        if (n == -1) break;
        v.push_back(n);
    }

    int x = v.size();
    if (x == 0) return 0;

    if (x == 1) {
        cout << v[0];
        return 0;
    }

    vector<int> d(x);
    d[0] = v[0];
    d[1] = max(v[0], v[1]);

    for (int i = 2; i < x; i++) {
        d[i] = max(d[i-1], d[i-2] + v[i]);
    }

    cout << d[x-1];
    return 0;
}
