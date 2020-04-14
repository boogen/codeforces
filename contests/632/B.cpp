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

const int maxn = 1e5+10;

int a[maxn];
int b[maxn];

void solve() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) 
        cin >> b[i];
    

    int minus = 0;
    int one = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < b[i] && one == 0) {
            cout << "NO" << endl;
            return;
        }
        if (a[i] > b[i] && minus == 0) {
            cout << "NO" << endl;
            return;
        }

        if (a[i] < 0)
            minus = i;
        if (a[i] > 0)
            one = i;

    }

    cout << "YES" << endl;
    
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
