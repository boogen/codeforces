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

ll n, m, k;

ll count(ll v) {
    ll res = 0;
    for (ll i = 1; i <= min(n, m); ++i)
        res += min(i * max(n, m), v) / i;

    return res;
}

int main() {
    cin >> n >> m >> k;

    ll l = 1; 
    ll r = n * m;

    ll res = 0;
    while (l <= r) {
        ll m = (l + r) / 2;
        
        ll v = count(m);
        if (v >= k) {
            res = m;
            r = m - 1;
        }
        else if (v < k) {
            l = m + 1;
        }
    }

    cout << res << endl;

}
