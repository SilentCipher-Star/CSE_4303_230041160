#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int level, trials;
    cin >> level >> trials;

    vector<pair<int,string>> grade_levels(level);

    for(int i = 0; i < level; i++) {
        cin >> grade_levels[i].first >> grade_levels[i].second;
    }

    sort(grade_levels.begin(), grade_levels.end()); // ascending by threshold(limit)

    while(trials--) {
        int score;
        cin >> score;

        string result = grade_levels[0].second; // lowest grade by default

        for (int i = 1; i < level; i++) {
            if (score < grade_levels[i].first)
                break;
            result = grade_levels[i].second;
        }

        cout << result << "\n";
    }

    return 0;
}
