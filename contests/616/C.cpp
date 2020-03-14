#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
 
#define ulong unsigned long long
#define ll long long
 
using namespace std;

int a[4000];
int dp[3501][3501];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int v = max(a[i], a[n - m + i]);
        dp[m][i] = v;
    }

    for (int i = m - 1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }


    int s = min(k + 1, m);
    cout << (*max_element(dp[s], dp[s] + s)) << endl;
}


int main() {
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        solve();
    }
}
