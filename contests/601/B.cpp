#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <set>
#include <queue>
#include <map>
#include <stack>
#define llong long long
#define ulong unsigned long long
 
using namespace std;
int a[1001];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 2) {
        cout << "-1" << endl;
        return;
    }
    if (m < n) {
        cout << "-1" << endl;
        return;
    }

    int cost = 0;
    for (int i = 0; i < n; ++i)
        cost += a[i];

    cost *= 2;
    cout << cost << endl;

    for (int i = 1; i < n; ++i) {
        cout << i << " " << (i + 1) << endl;
    }
    cout << n << " 1" << endl;
    
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}
