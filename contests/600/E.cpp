#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <set>
#include <queue>
#include <map>
 
#define llong long long
#define ulong unsigned long long
 
using namespace std;


int dp[1001000];

pair<int, int> an[100];


int main() {
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int x, c;
        cin >> x >> c;

        pair<int, int> p = make_pair( max(1, x - c), min(x + c, m));
        an[i] = p;
    }


    for (int i = m; i >= 1; --i) {
        dp[i] = dp[i + 1] + 1;

        for (int j = 0; j < n; ++j) {
            int l = an[j].first;
            int r = an[j].second;
            if (l <= i && i <= r) {
                dp[i] = dp[i + 1];
                break;
            }

            if (i < l) {
                int cost = l - i;
                dp[i] = min(dp[i], dp[min(m + 1, r + cost + 1) ] + cost);
            }
        }

    }


    cout << dp[1] << endl;

   
}
