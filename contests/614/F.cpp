#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
 
#define ulong unsigned long long
#define ll long long
 
using namespace std;


int cnt[5001];
ll dp[5001][5001];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        cnt[k]++;
    }

    for (int i = 2; i <= 5000; ++i) {
        for (int j = 1; j <= 5000; ++j) {
            dp[i][j] += dp[i - 1][j];
        }

        int v = i;
        for (int j = 2; j <= sqrt(i); ++j) {
            while (v % j == 0) {
                v /= j;
                dp[i][j]++;
            }
        }

        if (v > 1) 
            dp[i][v]++;
    }


    ll ans = 0;
    vector<int> best(5001, 1);
    for (int i = 0; i <= 5000; ++i) {
        if (cnt[i] == 0) {
            continue;
        }
        for (int j = 1; j <= 5000; ++j) {
            ans += dp[i][j] * cnt[i];
            if (dp[i][j] > 0) {
                best[i] = j;
            }
        }
    }


    while (*max_element(best.begin(), best.end()) > 1) {
        vector<int> freq(5001, 0);

        for (int i = 0; i <= 5000; ++i) {
            freq[best[i]] += cnt[i];
        }

        int prime = max_element(freq.begin(), freq.end()) - freq.begin();
        int c = freq[prime];

        if (c * 2 <= n)
            break;
        if (prime == 1) 
            break;

        ans -= c;
        ans += (n - c);

        for (int i = 0; i <= 5000; ++i) {
            if (best[i] != prime) {
                best[i] = 1;
            }
            else {
                dp[i][best[i]] -= 1;
                while(best[i] > 1 && dp[i][best[i]] == 0) {
                    best[i]--;
                }
            }
            
        }
        
    }

    cout << ans << endl;
    
}
