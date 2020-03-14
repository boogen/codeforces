#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
 
#define ulong unsigned long long
#define ll long long
 
using namespace std;

int dp[300000][100];

int main() {
    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < 30; ++j) {
            dp[i + 1][j] = dp[i][j];
        }
        dp[i + 1][s.at(i) - 'a']++;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        if (r - l > 0) {
            int cnt = 0;
            for (int j = 0; j < 30; ++j) {
                if (dp[r][j] - dp[l - 1][j] > 0) {
                    cnt++;
                }
            }
            if (cnt > 2) {
                cout << "Yes\n";
            }
            else if (cnt == 2 && s[l - 1] != s[r - 1]) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
        else {
            cout << "Yes\n";
        }
    }
}
