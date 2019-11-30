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

int a[200000 + 1];
llong mm[200000 + 1];
llong c[200000 + 1];

int main() {
    int n, m;
    cin >> n >> m;

    memset(mm, 0, sizeof(mm));
    memset(c, 0, sizeof(c));

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a + n);
    
    for (int i = 0; i < n; ++i) {
        mm[i % m] += a[i];

        c[i + 1] = c[i] + mm[i % m];
        cout << c[i + 1] << " ";
    }
    cout << endl;
}

