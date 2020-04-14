#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
 
#define ll long long
#define ulong unsigned long long
 
using namespace std;

const int maxn = 1e6+1;

ll a[maxn];
ll pref[maxn];

int check(int i, int j) {
    for (int x = i; x <= j; ++x) {
        for (int y = x; y <= j; ++y) {
            int sum = 0;
            for (int k = x; k <= y; ++k) 
                sum += a[k];

            if (sum == 0)
                return 0;
        }
    }
    
    return 1;
}

int main() {
    ll n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }


    map<ll, ll> c;
    ll bad = 0;
    ll all = n * (n + 1LL) / 2LL;

    ll good = 0;
    ll last = -1;
    c[0] = 0;
    for (int i = 1; i <= n; ++i) {
        ll s = pref[i];
        ll start = 0;
        ll len = i;
        if (c.find(s) != c.end()) {
            len = std::min(len, i - c[s] - 1);
        }
        len = std::min(len, i - last - 1);
        
        if (c.find(s) != c.end()) {
            last = std::max(c[s], last);
        }
        good += len;
        c[pref[i]] = i;
    }
    cout << good << endl;
}
